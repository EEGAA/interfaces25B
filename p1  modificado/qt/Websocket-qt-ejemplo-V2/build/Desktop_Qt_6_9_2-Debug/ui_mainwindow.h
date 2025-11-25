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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QRadioButton *radioButton_normal;
    QRadioButton *radioButton_pibote;
    QRadioButton *radioButton_curva;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(532, 340);
        QPalette palette;
        QBrush brush(QColor(191, 201, 84, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush);
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
        salirBTN->setGeometry(QRect(410, 250, 111, 31));
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
        label_2->setGeometry(QRect(10, 270, 231, 17));
        radioButton_normal = new QRadioButton(centralwidget);
        radioButton_normal->setObjectName("radioButton_normal");
        radioButton_normal->setGeometry(QRect(420, 70, 110, 22));
        radioButton_pibote = new QRadioButton(centralwidget);
        radioButton_pibote->setObjectName("radioButton_pibote");
        radioButton_pibote->setGeometry(QRect(420, 110, 110, 22));
        radioButton_curva = new QRadioButton(centralwidget);
        radioButton_curva->setObjectName("radioButton_curva");
        radioButton_curva->setGeometry(QRect(420, 150, 110, 22));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(250, 250, 41, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(250, 20, 31, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 532, 22));
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
        radioButton_normal->setText(QCoreApplication::translate("MainWindow", "Normal (1)", nullptr));
        radioButton_pibote->setText(QCoreApplication::translate("MainWindow", "Pibote (2)", nullptr));
        radioButton_curva->setText(QCoreApplication::translate("MainWindow", "Curva (3)", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " (N)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "(M)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
