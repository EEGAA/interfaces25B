#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <QWidget>
#include <QTimer>
#include <vector>

#include <QDebug>

class GameOfLife : public QWidget {
    Q_OBJECT

public:
    GameOfLife(QWidget *parent = nullptr);
    ~GameOfLife();  // Destructor
    void randomizeGrid();
    void clearGrid();
    void aliveAll();
    void pauseGen(bool bnd);
    void naveGen(int fila, int columna, int sentido);
    int getGridSize();
    void setGridSize(int newSize);
    int getCellSize();
    void setCellSize(int newSize);
    int getTimeGen();
    void setTimeGen(int newTime);
    void changePause();
    int getMapa();
    void setMapa(int newMapa);
    bool getRunning(){return running;}
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void nextGeneration();

private:
    //1 = mundo cuadrado, 2 = mundo toroidal, 3 = mundo infinito
    int mapa = 2;//mapa solo puede tener como valor 1, 2, o 3
    int cellSize = 11;
    int gridSize = 55;
    int timeGen = 100; //milisegundios
    QString aliveColor = "#FF6B6B";    // Rojo coral
    QString gridColor = "#4ECDC4";     // Verde azulado
    QString deadColor = "#dddddd";     // Gris muy claro
    std::vector<std::vector<bool>> grid;
    QTimer *timer;
    bool running;

    int countNeighbors(int x, int y, int mundo);
    void changeCell(int x, int y);
    //método para ajustar el tamaño
    void adjustSizeToGrid();
};

#endif // GAMEOFLIFE_H
