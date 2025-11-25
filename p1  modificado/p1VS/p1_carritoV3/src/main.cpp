#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsServer.h>   // arduinoWebSockets (Links2004)
#include <ArduinoJson.h>        // Benoit Blanchon
#include <ESPmDNS.h>            // mDNS / DNS-SD

// ==== FreeRTOS (tareas/colas) ====
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
// ==== Mis headers ====
#include "miPuenteH.hpp"
puenteH mtrs = {13, 12, 11, 10, 14, 9}; //IN1, IN2, IN3, IN4, pwmA, pwmB
// ====== ADC opcional ======
const int PIN_ADC = 4;//semilla random
// ====== CONFIG WiFi ======
 /*
 const char* ssid     = "A2501";
 const char* password = "A_2501//";
 const char* ssid     = "LACER_Alumnos";
 const char* password = "Conversion";*/
 const char* ssid     = "GWN571D04";
 const char* password = "ESP32CUCEI$$";
// ====== Servidor WebSocket ======
// ====== Hostname ======
String nombreHost;
#define puertoWS 81
WebSocketsServer servidorWS(puertoWS);
// ----------------------------------------------------------------------
//                   PROTOTIPOS (usados en varias secciones)
// ----------------------------------------------------------------------
String macSinDosPuntos() {
  String mac = WiFi.macAddress();
  mac.toLowerCase();
  String out;
  for (char c : mac) if (c != ':') out += c;
  return out;
}
String sufijoMAC6() {
  String m = macSinDosPuntos();
  return (m.length() >= 6) ? m.substring(m.length() - 6) : m;
}
void enviarJsonACliente(uint8_t idCliente, const JsonDocument& doc) {
  String out; serializeJson(doc, out);
  servidorWS.sendTXT(idCliente, out);
}
void difundirJson(const JsonDocument& doc) {
  String out; serializeJson(doc, out);
  servidorWS.broadcastTXT(out);
}
// ======================================================================
//        COLA / TASK DE MOTORES (CORE 1) - CONTROL POR millis()
// ======================================================================
enum class DirMov : uint8_t { Parado=0, Avanzar, Retroceder, Izquierda, Derecha, Parar };

struct CmdMotor {
  DirMov accion;
  uint32_t dur_ms;   // duración solicitada
  uint32_t t0_ms;    // (lo rellena el task)
  String tipoGriro; //normal pibote curva
};

static QueueHandle_t motorCmdQ = nullptr;
static TaskHandle_t motorTaskHandle = nullptr;

void MotorTask(void* arg) {
  (void)arg;
  CmdMotor cmd{DirMov::Parado, 0, 0, "normal"};

  bool enMovimiento = false;
  uint32_t t_fin = 0;

  for (;;) {
    // Preempción inmediata si llega nuevo comando
    CmdMotor nuevo;
    if (xQueueReceive(motorCmdQ, &nuevo, (TickType_t)0) == pdTRUE) {
      // Parar cualquier movimiento actual antes de aplicar el nuevo
      enMovimiento = false;
      mtrs.mtrStop();

      if (nuevo.accion == DirMov::Parar || nuevo.accion == DirMov::Parado || nuevo.dur_ms == 0) {
        enMovimiento = false;
      } else {
        // Aplicar movimiento
        switch (nuevo.accion) {
          case DirMov::Avanzar:     mtrs.adelante();  break;
          case DirMov::Retroceder:  mtrs.atras();     break;
          case DirMov::Izquierda:   mtrs.moveGiroL(cmd.tipoGriro); break;
          case DirMov::Derecha:     mtrs.moveGiroR(cmd.tipoGriro);   break;
          default:                  mtrs.mtrStop();   break;
        }
        nuevo.t0_ms = millis();
        t_fin = nuevo.t0_ms + nuevo.dur_ms;
        enMovimiento = true;

        StaticJsonDocument<128> ack;
        ack["tipo"] = "mover_inicio";
        difundirJson(ack);
      }
      cmd = nuevo;
    }

    // Verificar timeout por millis
    if (enMovimiento) {
      uint32_t ahora = millis();
      if ((int32_t)(ahora - t_fin) >= 0) {
        enMovimiento = false;
        mtrs.mtrStop();

        StaticJsonDocument<128> fin;
        fin["tipo"] = "mover_fin";
        difundirJson(fin);
      }
    }

    vTaskDelay(1); // ~1 ms
  }
}

// ====== Temporizadores y variables ======
volatile bool latidoRecibido = false;
unsigned long ultimoEnvioMs  = 0;
unsigned long CADA_MS        = 2000;

// ======================================================================
//                      EVENTOS WEBSOCKET
// ======================================================================
void onEventoWS(uint8_t idCliente, WStype_t tipo, uint8_t * payload, size_t longitud) {
  switch (tipo) {
    case WStype_CONNECTED: {
      IPAddress ip = servidorWS.remoteIP(idCliente);
      Serial.printf("[WS] Cliente %u conectado desde %s\n", idCliente, ip.toString().c_str());

      StaticJsonDocument<256> msg;
      msg["tipo"]        = "saludo";
      msg["mensaje"]     = "Servidor ESP32-S3 listo";
      msg["puerto"]      = puertoWS;
      msg["nombre_host"] = nombreHost;
      msg["mac"]         = WiFi.macAddress();
      enviarJsonACliente(idCliente, msg);
    } break;

    case WStype_DISCONNECTED:
      Serial.printf("[WS] Cliente %u desconectado\n", idCliente);
      break;

    case WStype_TEXT: {
      String recibido((char*)payload, longitud);
      Serial.printf("[WS] RX (%u bytes): %s\n", (unsigned)longitud, recibido.c_str());

      StaticJsonDocument<1024> doc;
      DeserializationError err = deserializeJson(doc, recibido);
      if (err) return;

      //const char* tipoMsg = doc["tipo"] | "";

      String tipoMsg = doc["tipo"].as<String>();

      if (tipoMsg == "latido") {
        latidoRecibido = true;
        StaticJsonDocument<160> ack;
        ack["tipo"]       = "latido_ok";
        ack["tiempo_ms"]  = (uint32_t)millis();
        enviarJsonACliente(idCliente, ack);
      }
      else if (tipoMsg == "mover") {
        // Esquema:
        // { "tipo":"mover", "accion":"avanzar|retroceder|izquierda|derecha|parar", "ms": 800 }
        const char* accionStr = doc["accion"] | "avanzar";
        uint32_t ms = doc["ms"] | 600;
        if (ms >= 8000) ms = 8000; // límite de seguridad

        DirMov a = DirMov::Avanzar;
        if      (strcmp(accionStr, "retroceder") == 0) a = DirMov::Retroceder;
        else if (strcmp(accionStr, "izquierda")  == 0) a = DirMov::Izquierda;
        else if (strcmp(accionStr, "derecha")    == 0) a = DirMov::Derecha;
        else if (strcmp(accionStr, "parar")      == 0) a = DirMov::Parar;

        String tipoGriro_ = doc["tipoGriro"].as<String>();

        CmdMotor cmd{ a, ms, 0, tipoGriro_};
        bool ok = (motorCmdQ && (xQueueSend(motorCmdQ, &cmd, 0) == pdTRUE));

        StaticJsonDocument<192> ack2;
        ack2["tipo"]   = ok ? "mover_ack" : "mover_err";
        ack2["accion"] = accionStr;
        ack2["ms"]     = ms;
        ack2["tipoGriro"] = tipoGriro_;
        enviarJsonACliente(idCliente, ack2);
      }
      else if(tipoMsg == "setPWM"){
        int myPWM = doc["pwm"].as<int>();
        mtrs.setPWM(myPWM);
      }
    } break;

    default:
      break;
  }
}

// ======================================================================
//                           mDNS
// ======================================================================
void iniciarMDNSyDNSSD() {
  nombreHost = "esp32-" + sufijoMAC6();
  nombreHost.toLowerCase();

  if (MDNS.begin(nombreHost.c_str())) {
    MDNS.addService("ws", "tcp", puertoWS);
    MDNS.addServiceTxt("ws", "tcp", "proto", "json");
    Serial.println("[mDNS] Iniciado: " + nombreHost + ".local");
  } else {
    Serial.println("[mDNS] Error iniciando mDNS");
  }
}

void setup(){
  Serial.begin(115200);
  delay(200);

  //semilla para random (mejjor variacion em modo simulado)
  pinMode(PIN_ADC, INPUT);
  analogReadResolution(12);
  randomSeed(analogRead(PIN_ADC));

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("\nConetado a la red: ");
  Serial.println(ssid);
  int cont = 0;
  while(WiFi.status() != WL_CONNECTED){
    Serial.print("..");
    if(cont == 10)
      ESP.restart();//Si la esp no se conecta despues de 10 s se reincia
    cont++;
    delay(1000);
  }
  Serial.println();
  Serial.print("IP: "); Serial.println(WiFi.localIP());

  iniciarMDNSyDNSSD();

  // === Motores: pines e iniciar apagados por defecto ===
  //////motores_init_pines();
  /////motores_parar_total();

  // === Cola y Task de motores (core 1) ===
  motorCmdQ = xQueueCreate(5, sizeof(CmdMotor));
  if (!motorCmdQ) {
    Serial.println("[MOTOR] ERROR: no se pudo crear la cola de comandos");
  } else {
    BaseType_t ok = xTaskCreatePinnedToCore(
      MotorTask,
      "MotorTask",
      4096,       // stack
      nullptr,
      2,          // prioridad
      &motorTaskHandle,
      1           // core 1 (el otro CPU)
    );
    if (ok != pdPASS) {
      Serial.println("[MOTOR] ERROR: no se pudo crear el task de motores");
    } else {
      Serial.println("[MOTOR] Task de motores iniciado en core 1");
    }
  }

  // === WebSocket ===
  servidorWS.begin();
  servidorWS.onEvent(onEventoWS);
  Serial.println("Servidor WebSocket en ws://" + nombreHost + ".local:81");
}


void loop(){
  servidorWS.loop();

  unsigned long ahora = millis();
  if(latidoRecibido && (ahora - ultimoEnvioMs >= CADA_MS)){

    ultimoEnvioMs = millis();
  }


}
