/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *adelante;
    QPushButton *atras;
    QPushButton *izquierda;
    QPushButton *derecha;
    QPushButton *salirBTN;
    QSlider *verticalSliderPWM;
    QLCDNumber *lcdNumberPWM;
    QPushButton *pushButtonPWM;
    QLabel *label;
    QPushButton *alto;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(408, 348);
        QPalette palette;
        QBrush brush(QColor(111, 195, 192, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        adelante = new QPushButton(centralwidget);
        adelante->setObjectName("adelante");
        adelante->setGeometry(QRect(90, 20, 70, 70));
        atras = new QPushButton(centralwidget);
        atras->setObjectName("atras");
        atras->setGeometry(QRect(90, 180, 70, 70));
        izquierda = new QPushButton(centralwidget);
        izquierda->setObjectName("izquierda");
        izquierda->setGeometry(QRect(170, 100, 70, 70));
        derecha = new QPushButton(centralwidget);
        derecha->setObjectName("derecha");
        derecha->setGeometry(QRect(10, 100, 70, 70));
        salirBTN = new QPushButton(centralwidget);
        salirBTN->setObjectName("salirBTN");
        salirBTN->setGeometry(QRect(280, 270, 111, 31));
        verticalSliderPWM = new QSlider(centralwidget);
        verticalSliderPWM->setObjectName("verticalSliderPWM");
        verticalSliderPWM->setGeometry(QRect(247, 39, 31, 211));
        verticalSliderPWM->setMinimum(0);
        verticalSliderPWM->setMaximum(258);
        verticalSliderPWM->setSingleStep(1);
        verticalSliderPWM->setOrientation(Qt::Orientation::Vertical);
        lcdNumberPWM = new QLCDNumber(centralwidget);
        lcdNumberPWM->setObjectName("lcdNumberPWM");
        lcdNumberPWM->setGeometry(QRect(277, 70, 111, 61));
        pushButtonPWM = new QPushButton(centralwidget);
        pushButtonPWM->setObjectName("pushButtonPWM");
        pushButtonPWM->setGeometry(QRect(280, 160, 111, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 40, 101, 31));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        alto = new QPushButton(centralwidget);
        alto->setObjectName("alto");
        alto->setGeometry(QRect(100, 110, 50, 50));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 260, 231, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 280, 231, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 300, 231, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 408, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        adelante->setText(QCoreApplication::translate("MainWindow", "Adelante", nullptr));
        atras->setText(QCoreApplication::translate("MainWindow", "Atras", nullptr));
        izquierda->setText(QCoreApplication::translate("MainWindow", "Derecha", nullptr));
        derecha->setText(QCoreApplication::translate("MainWindow", "Izquierda", nullptr));
        salirBTN->setText(QCoreApplication::translate("MainWindow", "(x) SALIR", nullptr));
        pushButtonPWM->setText(QCoreApplication::translate("MainWindow", "(z) send PWM", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PWM 8 bits", nullptr));
        alto->setText(QCoreApplication::translate("MainWindow", "Parar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "c = PWM recomendado", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "shift = +10 PWM", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "ctrl = -10 PWM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
