#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMessageBox>
#include "gameoflife.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString setSALIRButton = "QPushButton {"
                             "   border-radius: 10px;"
                             "   border: 2px solid #555;"
                             "   background-color: #4ECDC4;"
                             "   padding: 5px;"
                             "   color: black;"
                             "   font-size: 18px;"
                             "}"
                             "QPushButton:hover {"
                             "   background-color: #FF6B6B;"  // Color al pasar el mouse
                             "}"
                             "QPushButton:pressed {"
                             "   background-color: #8E0303;"  // Color al presionar
                             "}";
    QString setPAUSAButton = "QPushButton {"
                             "   border-radius: 10px;"
                             "   border: 2px solid #555;"
                             "   background-color: #7EAAF1;"
                             "   padding: 5px;"
                             "   color: black;"
                             "   font-size: 18px;"
                             "}"
                             "QPushButton:hover {"
                             "   background-color: #8B7EF1;"  // Color al pasar el mouse
                             "}"
                             "QPushButton:pressed {"
                             "   background-color: #4ECDC4;"  // Color al presionar
                             "}";
    QString setPLAYButton = "QPushButton {"
                             "   border-radius: 10px;"
                             "   border: 2px solid #555;"
                             "   background-color: #8B7EF1;"
                             "   padding: 5px;"
                             "   color: black;"
                             "   font-size: 18px;"
                             "}"
                             "QPushButton:hover {"
                             "   background-color: #7EAAF1;"  // Color al pasar el mouse
                             "}"
                             "QPushButton:pressed {"
                             "   background-color: #4ECDC4;"  // Color al presionar
                             "}";
    QString setCEROSButton = "QPushButton {"
                             "   border-radius: 10px;"
                             "   border: 2px solid #555;"
                             "   background-color: #DDA98D;"
                             "   padding: 5px;"
                             "   color: black;"
                             "   font-size: 18px;"
                             "}"
                             "QPushButton:hover {"
                             "   background-color: #DD8D99;"  // Color al pasar el mouse
                             "}"
                             "QPushButton:pressed {"
                             "   background-color: #FF6B6B;"  // Color al presionar
                             "}";
    QString setRANDOMButton = "QPushButton {"
                             "   border-radius: 10px;"
                             "   border: 2px solid #555;"
                             "   background-color: #91D9BF;"
                             "   padding: 5px;"
                             "   color: black;"
                             "   font-size: 18px;"
                             "}"
                             "QPushButton:hover {"
                             "   background-color: #ABD991;"  // Color al pasar el mouse
                             "}"
                             "QPushButton:pressed {"
                             "   background-color: #91D99A;"  // Color al presionar
                             "}";
    QString setAYUDAButton = "QPushButton {"
                              "   border-radius: 10px;"
                              "   border: 2px solid #555;"
                              "   background-color: #198DE6;"
                              "   padding: 5px;"
                              "   color: black;"
                              "   font-size: 18px;"
                              "}"
                              "QPushButton:hover {"
                              "   background-color: #34CB64;"  // Color al pasar el mouse
                              "}"
                              "QPushButton:pressed {"
                              "   background-color: #7219E6;"  // Color al presionar
                              "}";
    QString labelStyle =
        "QLabel {"
        "    color: #000000;"        /* Color del texto */
        "    font-size: 20px;"       /* Tamaño del texto */
        "    font-weight: bold;"     /* Negritas */
        "    background-color: #DDDDDD;" /* Fondo */
        "    border: 1px solid #444;"    /* Borde */
        "    border-radius: 5px;"    /* Bordes redondeados */
        "    padding: 5px;"          /* Espaciado interno */
        "}";

    QString setDialstyle = "QDial {"
                             "    background-color: #f0f0f0;"
                             "    border: 1px solid #ccc;"
                             "    border-radius: 25px;"
                             "}"
                             "QDial::handle {"
                             "    background-color: #FF6B6B;"
                             "    border: 1px solid #d04c4c;"
                             "    border-radius: 8px;"
                             "    width: 16px;"
                             "    height: 16px;"
                             "}";

    QString setLCDstyle = "QLCDNumber {"
                          "   background-color: black;"       // Fondo negro
                          "   color: #f39c12;"               // Dígitos naranjaws (estilo clásico de LCD)
                          "   border: 2px solid #f39c12;"    // Borde naranja
                          "   border-radius: 8px;"           // Bordes redondeados
                          "   font-size: 33px;"              // Tamaño de los dígitos
                          "   font-weight: bold;"
                          "}";

    QString radioButtonGradient =
        "QRadioButton {"
        "   spacing: 10px;"
        "   color: #2c3e50;"
        "   font-size: 15px;"
        "   font-weight: bold;"
        "}"
        "QRadioButton::indicator {"
        "   width: 20px;"
        "   height: 20px;"
        "   border-radius: 10px;"
        "   border: 2px solid #7f8c8d;"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #ecf0f1, stop:1 #bdc3c7);"
        "}"
        "QRadioButton::indicator:checked {"
        "   border: 2px solid #e74c3c;"
        "   background: qradialgradient(cx:0.5, cy:0.5, radius:0.4, fx:0.5, fy:0.5, "
        "                               stop:0 #e74c3c, stop:1 #c0392b);"
        "}"
        "QRadioButton::indicator:hover {"
        "   border: 2px solid #3498db;"
        "}"
        "QRadioButton::indicator:checked:hover {"
        "   border: 2px solid #2980b9;"
        "   background: qradialgradient(cx:0.5, cy:0.5, radius:0.4, fx:0.5, fy:0.5, "
        "                               stop:0 #3498db, stop:1 #2980b9);"
        "}";

    void keyPressEvent(QKeyEvent *event) override;
    void setDialValue(int x);
    void keyAddTime(int key);
    void pausaStyle(bool bnd);
private slots:


    void on_pushButton_salir_clicked();

    void on_dial_sliderMoved(int position);

    void on_dial_sliderReleased();

    void on_pushButton_pausa_clicked();

    void on_pushButton_ceros_clicked();

    void on_pushButton_random_clicked();

    void on_pushButton_ayuda_clicked();

    void on_radioButton_torodal_clicked(bool checked);

    void on_radioButton_cuadrado_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    GameOfLife *gameOfLifeWidget;
    void mostrarAyuda();
};
#endif // MAINWINDOW_H
