#include <Arduino.h>
class puenteH{
private:
  int a1, a2, b1, b2, pinPWMa, pinPWMb; //IN1, IN2, IN3, IN4, pwmA, pwmB
  const int freq = 500;       // Frecuencia PWM (Hz) ~ para motores DC entre 500 y 5000
  const int pwmChannelA = 0;  // Canal PWM (0-15)
  const int pwmChannelB = 1;
  const int resolution = 8;  //ps 0 a 255
  int pwm;
public:
  puenteH(int a, int b, int c, int d, int pwmA, int pwmB){
    this->a1 = a; this->a2 = b;
    this->b1 = c; this->b2 = d;
    pinMode(a1, OUTPUT);
    pinMode(a2, OUTPUT);
    pinMode(b1, OUTPUT);
    pinMode(b2, OUTPUT);

    this->pinPWMa = pwmA;
    this->pinPWMb = pwmB;
    pinMode(pinPWMa, OUTPUT);
    pinMode(pinPWMb, OUTPUT);

    ledcSetup(pwmChannelA, freq, resolution);
    ledcSetup(pwmChannelB, freq, resolution);
    ledcAttachPin(pinPWMa, pwmChannelA);
    ledcAttachPin(pinPWMb, pwmChannelB);

    pwm = 128;
    mtrStop();
  }

  void setPWM(int pwm){
    if(pwm>=0 && pwm<=255)
      this->pwm = pwm;
  }
  void setPWMmas(){
    if(pwm < 255)
      pwm++;
  }
  void setPWMmenos(){
    if(pwm > 0)
      pwm--;
  }
  int getPWM(){
    return pwm;
  }
  
  void mtrA(bool dir, int Vpwm){
    ledcWrite(pwmChannelA, Vpwm);
    digitalWrite(a1, dir);
    digitalWrite(a2, !dir);
  }
  void mtrB(bool dir, int Vpwm){
    ledcWrite(pwmChannelB, Vpwm);
    digitalWrite(b1, dir);
    digitalWrite(b2, !dir);
  }
  void mtrStop(){
    ledcWrite(pwmChannelA, 0);
    ledcWrite(pwmChannelB, 0);
    digitalWrite(a1, 0);
    digitalWrite(a2, 0);
    digitalWrite(b1, 0);
    digitalWrite(b2, 0);
  }
  
  void adelante(){
    mtrA(0, pwm);
    mtrB(1, pwm);
  }
  void atras(){
    mtrA(1, pwm);
    mtrB(0, pwm);
  }


  void derecha(){
    mtrA(1, pwm);
    mtrB(1, pwm);
  }
  void izquierda(){
    mtrA(0, pwm);
    mtrB(0, pwm);
  }

  void derechaP(){
    mtrStop();
    mtrB(1, pwm);
  }
  void izquierdaP(){
    mtrStop();
    mtrA(0, pwm);
  }
  
  void derechaC(){
    mtrA(0, 128);
    mtrB(1, 255);
  }
  void izquierdaC(){
    mtrA(0, 255);
    mtrB(1, 128);
  }
  void moveGiroR(String giro){
    if(giro == "normal")
      derecha();
    else if(giro == "pibote")
      derechaP();
    else if(giro == "curva")
      derechaC();
  }
  void moveGiroL(String giro){
    if(giro == "normal")
      izquierda();
    else if(giro == "pibote")
      izquierdaP();
    else if(giro == "curva")
      izquierdaC();
  }
};
