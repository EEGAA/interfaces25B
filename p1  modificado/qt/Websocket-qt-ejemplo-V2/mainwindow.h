#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>
#include <QTimer>
#include <QUrl>
#include <QSet>
#include <QKeyEvent>
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString styleButtonDir = "QPushButton{"
                             "color: black;" //color de la letra en el boton
                             "background: #2ecc71;"
                             "border-radius: 35px;"
                             "border: 2px solid #01631f;"
                             "}"
                             "QPushButton:hover {"
                             "background-color: #1d8348;"  // Color al pasar el mouse
                             "}"
                             "QPushButton:pressed {"
                             "background-color: #e67e22;"  // Color al presionar
                             "}";
    QString styleButtonStop = "QPushButton{"
                             "color: black;" //color de la letra en el boton
                             "background: #2ecc71;"
                             "border-radius: 25px;"
                             "border: 2px solid #01631f;"
                             "}"
                             "QPushButton:hover {"
                             "background-color: #a93226;"  // Color al pasar el mouse
                             "}"
                             "QPushButton:pressed {"
                             "background-color: #e67e22;"  // Color al presionar
                             "}";
    QString setSALIRButton = "QPushButton {"
                             "   border-radius: 10px;"
                             "   border: 2px solid #555;"
                             "   background-color: #a93226;"
                             "   padding: 5px;"
                             "}"
                             "QPushButton:hover {"
                             "   background-color: #c0392b;"  // Color al pasar el mouse
                             "}"
                             "QPushButton:pressed {"
                             "   background-color: #a93226;"  // Color al presionar
                             "}";
    QString styleLCDnumberOK = "QLCDNumber {"
                                  "   background-color: black;"       // Fondo negro
                                  "   color: #00FF00;"               // Dígitos verdes (estilo clásico de LCD)
                                  "   border: 2px solid #555555;"    // Borde gris
                                  "   border-radius: 8px;"           // Bordes redondeados
                                  "}";
    QString styleLCDnumberChange = "QLCDNumber {"
                                   "   background-color: black;"       // Fondo negro
                                   "   color: #f39c12;"               // Dígitos naranjaws (estilo clásico de LCD)
                                   "   border: 2px solid #f39c12;"    // Borde naranja
                                   "   border-radius: 8px;"           // Bordes redondeados
                                   "}";
    QString preSetTimeButton = "QPushButton {"
                               "   border-radius: 10px;"
                               "   border: 2px solid #555;"
                               "   background-color: #e67e22;"
                               "   padding: 5px;"
                               "}"
                               "QPushButton:hover {"
                               "   background-color:  #ca6f1e;"  // Color al pasar el mouse
                               "}"
                               "QPushButton:pressed {"
                               "   background-color: #e67e22;"  // Color al presionar
                               "}";
    QString preSetButton = "QPushButton {"
                           "   border-radius: 10px;"
                           "   border: 2px solid #555;"
                           "   background-color: #4CAF50;"
                           "   padding: 5px;"
                           "}"
                           "QPushButton:hover {"
                           "   background-color: #45a049;"  // Color al pasar el mouse
                           "}"
                           "QPushButton:pressed {"
                           "   background-color: #3e8e41;"  // Color al presionar
                           "}";
    QString c =
                "QSlider::groove:vertical {"
                "    border: 2px solid #555;"
                "    width: 12px;"
                "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                "    stop:0 #ff0000, stop:0.5 #ffff00, stop:1 #00ff00);"
                "    border-radius: 6px;"
                "}"
                "QSlider::handle:vertical {"
                "    background: #ffffff;"
                "    border: 2px solid #333;"
                "    height: 25px;"
                "    width: 20px;"
                "    margin: 0 -6px;"
                "    border-radius: 12px;"
                "}"
                "QSlider::handle:vertical:pressed {"
                "    background: #eeeeee;"
                    "}";
    QString e =
                "QSlider::groove:vertical {"
                "    border: 2px solid #3a3a3a;"
                "    background: #4CAF50;"
                "    width: 15px;"
                "    border-radius: 2px;"
                "}"
                "QSlider::sub-page:vertical {"
                "    background: #2d2d2d;"
                "    border-radius: 2px;"
                "}"
                "QSlider::handle:vertical {"
                "    background: #ffffff;"
                "    border: 2px solid #3a3a3a;"
                "    height: 25px;"
                "    width: 25px;"
                "    margin: 0 -8px;"
                "    border-radius: 12px;"
                "}"
                "QSlider::handle:vertical:hover {"
                "    background: #f0f0f0;"
                "}";
    QString radioButtonStyle =
        "QRadioButton {"
        "   spacing: 8px;"
        "   color: #333333;"
        "   font-size: 14px;"
        "   font-weight: normal;"
        "}"
        "QRadioButton::indicator {"
        "   width: 16px;"
        "   height: 16px;"
        "   border-radius: 8px;"
        "   border: 2px solid #999999;"
        "   background-color: #ffffff;"
        "}"
        "QRadioButton::indicator:checked {"
        "   border: 2px solid #2ecc71;"
        "   background-color: #2ecc71;"
        "}"
        "QRadioButton::indicator:hover {"
        "   border: 2px solid #666666;"
        "}"
        "QRadioButton::indicator:checked:hover {"
        "   border: 2px solid #973E30;"
        "   background-color: #973E30;"
        "}";
    QString colorLabel = "color: #000000;";
    bool curva = false;
    QString aux2;

private slots:
    // WebSocket
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(const QString &message);
#if QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)
    void onError(QAbstractSocket::SocketError error);
#else
    void onError(QAbstractSocket::SocketError error);
#endif
    void tryReconnect();

    // Keep-alive
    void sendPing();
    void onPong(quint64 elapsedTime, const QByteArray &payload);
    void onStateChanged(QAbstractSocket::SocketState s);



    void on_salirBTN_clicked();

    void on_verticalSliderPWM_sliderMoved(int position);

    void on_pushButtonPWM_clicked();

    void on_verticalSliderPWM_actionTriggered();

    void on_radioButton_normal_clicked(bool checked);

    void on_radioButton_pibote_clicked(bool checked);

    void on_radioButton_curva_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    int time = 1500;
    int m_keyMoveMs = time;     // duración por pulsación
    QSet<int> m_held;          // teclas actualmente presionadas
    void handleKeyMove(int key, bool pressed);

    QWebSocket *m_webSocket;
    QTimer m_reconnectTimer;
    QTimer m_pingTimer;
    QUrl m_url;

    int    m_backoffMs = 2000;
    const  int m_backoffMaxMs = 30000;
    int    m_consecutiveFailures = 0;
    qint64 m_lastPongMs = 0;

    void openSocket();
    void sendMover(const QString& accion, int ms = 600);
    void sendPWMmtrs();

    //Para poder decidir el tipo de vuelta se utiliza esta variable
    QString tipoGiro; // normal pibote curva
};

#endif // MAINWINDOW_H
