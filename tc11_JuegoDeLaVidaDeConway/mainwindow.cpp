#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameOfLifeWidget(new GameOfLife(this))
{
    ui->setupUi(this);

    QWidget *gameContainer = this->findChild<QWidget*>("gameContainer");
    if (gameContainer) {
        // Crear un layout para el contenedor
        QVBoxLayout *containerLayout = new QVBoxLayout(gameContainer);
        containerLayout->setContentsMargins(0, 0, 0, 0);  // Sin márgenes

        // Agregar el juego al contenedor
        containerLayout->addWidget(gameOfLifeWidget);

        // Centrar el widget del juego en el contenedor
        containerLayout->setAlignment(Qt::AlignCenter);
    }
    gameOfLifeWidget->setFocus();  // ESTA LÍNEA ES CLAVE - dar foco inicial al juego

    ui->pushButton_salir->setStyleSheet(setSALIRButton);
    pausaStyle(false);
    ui->pushButton_ceros->setStyleSheet(setCEROSButton);
    ui->pushButton_random->setStyleSheet(setRANDOMButton);
    ui->pushButton_ayuda->setStyleSheet(setAYUDAButton);
    ui->label_dialTime->setText("Tiempo entre generaciones [ms]");
    ui->label_dialTime->setStyleSheet(labelStyle);
    ui->label_bordes->setText("Bordes del mundo");
    ui->label_bordes->setStyleSheet(labelStyle);

    ui->dial->setStyleSheet(setDialstyle);
    ui->lcdNumber->setStyleSheet(setLCDstyle);

    ui->dial->setValue(gameOfLifeWidget->getTimeGen());
    ui->lcdNumber->display(gameOfLifeWidget->getTimeGen());

    ui->radioButton_cuadrado->setStyleSheet(radioButtonGradient);
    ui->radioButton_torodal->setStyleSheet(radioButtonGradient);

    ui->radioButton_torodal->setChecked(true);
    gameOfLifeWidget->pauseGen(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    int key = event->key();
    switch (key) {
    case Qt::Key_Escape:
        this->close();
        break;
    case Qt::Key_P:
        gameOfLifeWidget->changePause();
        pausaStyle(gameOfLifeWidget->getRunning());
        break;
    case Qt::Key_R:
        gameOfLifeWidget->randomizeGrid();
        break;
    case Qt::Key_C:
        gameOfLifeWidget->clearGrid();
        break;
    case Qt::Key_1:
        gameOfLifeWidget->naveGen(10,10,0);
        break;
    case Qt::Key_2:
        gameOfLifeWidget->naveGen(10,10,1);
        break;
    case Qt::Key_3:
        gameOfLifeWidget->naveGen(10,10,2);
        break;
    case Qt::Key_4:
        gameOfLifeWidget->naveGen(10,10,3);
        break;
    case Qt::Key_A:
        gameOfLifeWidget->aliveAll();
        break;
    case Qt::Key_Shift:
    case Qt::Key_Control:
        keyAddTime(key);
        break;
    case Qt::Key_H:
        mostrarAyuda();
        break;
    case Qt::Key_Q:
        gameOfLifeWidget->setMapa(1);
        ui->radioButton_cuadrado->setChecked(true);
        break;
    case Qt::Key_W:
        gameOfLifeWidget->setMapa(2);
        ui->radioButton_torodal->setChecked(true);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_salir_clicked()
{
    this->close();
}


void MainWindow::on_dial_sliderMoved(int position)
{
    setDialValue(position);
}


void MainWindow::on_dial_sliderReleased()
{
    int x = ui->dial->value();
    setDialValue(x);
}


void MainWindow::on_pushButton_pausa_clicked()
{
    gameOfLifeWidget->changePause();
    pausaStyle(gameOfLifeWidget->getRunning());
}


void MainWindow::on_pushButton_ceros_clicked()
{
    gameOfLifeWidget->clearGrid();
}


void MainWindow::on_pushButton_random_clicked()
{
    gameOfLifeWidget->randomizeGrid();
}

void MainWindow::setDialValue(int x){
    ui->lcdNumber->display(x);
    ui->dial->setValue(x);
    gameOfLifeWidget->setTimeGen(x);
}

void MainWindow::keyAddTime(int key){
    int min = ui->dial->minimum(), max = ui->dial->maximum(),
        act = ui->dial->value(), change = 25;
    if(key == Qt::Key_Shift){
        if((max - act) < change)
            setDialValue(max);
        else
            setDialValue(act + change);

    }else if(key == Qt::Key_Control){
        if((act - min) < change)
            setDialValue(min);
        else
            setDialValue(act - min);
    }
}

void MainWindow::mostrarAyuda()
{
    // Crear y configurar el mensaje de ayuda
    QMessageBox ayudaBox;
    ayudaBox.setWindowTitle("Ayuda - App del Juego de la Vida");
    ayudaBox.setIcon(QMessageBox::Information);
    ayudaBox.setFixedSize(556, 900);  // Tamaño personalizado

    // Texto formateado de ayuda
    QString textoAyuda =
        "<h2>Controles del Juego de la Vida</h2>"
        "<p><b>Teclas principales:</b></p>"
        "<ul>"
        "<li><b>P:</b> Pausar/Reanudar la simulación</li>"
        "<li><b>R:</b> Generar un grid aleatorio</li>"
        "<li><b>C:</b> Limpiar el grid</li>"
        "<li><b>A:</b> Todas las celulas viven</li>"
        "<li><b>Q:</b> Mundo cuadrado</li>"
        "<li><b>W:</b> Mundo toroidal</li>"
        "<li><b>Shift:</b> Aumenta 25ms el intervalo entre generaciones</li>"
        "<li><b>Ctrl:</b> Disminuye 25ms el intervalo entre generaciones</li>"
        "<li><b>1, 2, 3, 4:</b> Colocar diferentes patrones de \"planeadores\"</li>"
        "<li><b>H:</b> Mostrar esta ayuda</li>"
        "<li><b>Esc:</b> Salir de la aplicación</li>"
        "</ul>"
        "<p><b>Controles del mouse:</b></p>"
        "<ul>"
        "<li><b>Clic izquierdo:</b> Activar/Desactivar celdas</li>"
        "</ul>"
        "<p><b>Controles adicionales:</b></p>"
        "<ul>"
        "<li><b>Dial:</b> Controlar velocidad de generación (25-2000 ms)</li>"
        "</ul>"
        "<hr>"
        "<p><i>El Juego de la Vida es un autómata celular desarrollado por John Conway</i></p>"
        "<p><i>Esta app fue programada por Erick Grimaldo; Qt creator C++  Diseño de interfaces 25B</i></p>";

    ayudaBox.setText(textoAyuda);

    // Configurar el estilo de la ventana de ayuda
    ayudaBox.setStyleSheet(
        "QMessageBox {"
        "   background-color: #F0F0F0;"
        "   font-size: 14px;"
        "}"
        "QMessageBox QLabel {"
        "   color: #333333;"
        "   font-size: 14px;"
        "}"
        "QMessageBox QPushButton {"
        "   background-color: #4ECDC4;"
        "   border: 2px solid #555;"
        "   border-radius: 5px;"
        "   padding: 5px 10px;"
        "   font-size: 14px;"
        "}"
        "QMessageBox QPushButton:hover {"
        "   background-color: #FF6B6B;"
        "}"
        );

    // Mostrar la ventana de ayuda (modal - bloquea la ventana principal)
    ayudaBox.exec();
}


void MainWindow::on_pushButton_ayuda_clicked()
{
    mostrarAyuda();
}

void MainWindow::on_radioButton_torodal_clicked(bool checked)
{
    if(checked)
        gameOfLifeWidget->setMapa(2);
}


void MainWindow::on_radioButton_cuadrado_clicked(bool checked)
{
    if(checked)
        gameOfLifeWidget->setMapa(1);
}

void MainWindow::pausaStyle(bool bnd){
    if(!bnd){
        ui->pushButton_pausa->setStyleSheet(setPLAYButton);
        ui->pushButton_pausa->setText("Reanudar");
    }else{
        ui->pushButton_pausa->setStyleSheet(setPAUSAButton);
        ui->pushButton_pausa->setText("Pausa");
    }
}
