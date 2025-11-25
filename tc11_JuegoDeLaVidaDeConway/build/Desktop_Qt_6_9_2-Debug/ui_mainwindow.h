/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_salir;
    QLCDNumber *lcdNumber;
    QDial *dial;
    QLabel *label_dialTime;
    QWidget *gameContainer;
    QPushButton *pushButton_pausa;
    QPushButton *pushButton_ceros;
    QPushButton *pushButton_random;
    QPushButton *pushButton_ayuda;
    QRadioButton *radioButton_cuadrado;
    QRadioButton *radioButton_torodal;
    QLabel *label_bordes;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(970, 606);
        QPalette palette;
        QBrush brush(QColor(204, 204, 204, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush);
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_salir = new QPushButton(centralwidget);
        pushButton_salir->setObjectName("pushButton_salir");
        pushButton_salir->setGeometry(QRect(850, 550, 101, 41));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(805, 80, 91, 81));
        dial = new QDial(centralwidget);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(685, 70, 111, 101));
        dial->setMinimum(25);
        dial->setMaximum(2000);
        label_dialTime = new QLabel(centralwidget);
        label_dialTime->setObjectName("label_dialTime");
        label_dialTime->setGeometry(QRect(620, 19, 321, 51));
        gameContainer = new QWidget(centralwidget);
        gameContainer->setObjectName("gameContainer");
        gameContainer->setGeometry(QRect(0, 0, 606, 606));
        pushButton_pausa = new QPushButton(centralwidget);
        pushButton_pausa->setObjectName("pushButton_pausa");
        pushButton_pausa->setGeometry(QRect(740, 180, 101, 41));
        pushButton_ceros = new QPushButton(centralwidget);
        pushButton_ceros->setObjectName("pushButton_ceros");
        pushButton_ceros->setGeometry(QRect(630, 550, 101, 41));
        pushButton_random = new QPushButton(centralwidget);
        pushButton_random->setObjectName("pushButton_random");
        pushButton_random->setGeometry(QRect(630, 350, 101, 41));
        pushButton_ayuda = new QPushButton(centralwidget);
        pushButton_ayuda->setObjectName("pushButton_ayuda");
        pushButton_ayuda->setGeometry(QRect(740, 550, 101, 41));
        radioButton_cuadrado = new QRadioButton(centralwidget);
        radioButton_cuadrado->setObjectName("radioButton_cuadrado");
        radioButton_cuadrado->setGeometry(QRect(790, 351, 110, 22));
        radioButton_torodal = new QRadioButton(centralwidget);
        radioButton_torodal->setObjectName("radioButton_torodal");
        radioButton_torodal->setGeometry(QRect(790, 391, 110, 22));
        label_bordes = new QLabel(centralwidget);
        label_bordes->setObjectName("label_bordes");
        label_bordes->setGeometry(QRect(750, 300, 191, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_salir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        label_dialTime->setText(QCoreApplication::translate("MainWindow", "a;joednfa;jednca;fej;ajkwnef;ajwenf;aen", nullptr));
        pushButton_pausa->setText(QCoreApplication::translate("MainWindow", "Pausa", nullptr));
        pushButton_ceros->setText(QCoreApplication::translate("MainWindow", "Ceros", nullptr));
        pushButton_random->setText(QCoreApplication::translate("MainWindow", "Random", nullptr));
        pushButton_ayuda->setText(QCoreApplication::translate("MainWindow", "\302\277Ayuda?", nullptr));
        radioButton_cuadrado->setText(QCoreApplication::translate("MainWindow", "Cuadrado", nullptr));
        radioButton_torodal->setText(QCoreApplication::translate("MainWindow", "Toroidal", nullptr));
        label_bordes->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
