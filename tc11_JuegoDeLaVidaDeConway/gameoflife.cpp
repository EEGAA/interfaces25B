#include "gameoflife.h"
#include <QPainter>
#include <QMouseEvent>
#include <random>
#include <QResizeEvent>
GameOfLife::GameOfLife(QWidget *parent) : QWidget(parent) {
    grid.resize(gridSize, std::vector<bool>(gridSize, false));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GameOfLife::nextGeneration);
    randomizeGrid();
    // Configurar la política de tamaño
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // Ajustar el tamaño inicial
    adjustSizeToGrid();
    timer->start(timeGen);
    running = true;
}

// Destructor
GameOfLife::~GameOfLife() {
    // Detener el timer antes de destruir
    if (timer && timer->isActive()) {
        timer->stop();
    }

    // Qt maneja automáticamente la destrucción del timer
    // porque fue creado con 'this' como padre
    // No es necesario delete explícito
}

// Nuevo método para ajustar el tamaño
void GameOfLife::adjustSizeToGrid() {
    int totalSize = gridSize * cellSize;
    setFixedSize(totalSize, totalSize);
}
void GameOfLife::randomizeGrid() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            grid[i][j] = dis(gen);
        }
    }
    update();
}

void GameOfLife::clearGrid(){
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            grid[i][j] = 0;
        }
    }
    update();
}
void GameOfLife::aliveAll(){
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            grid[i][j] = 1;
        }
    }
    update();
}
void GameOfLife::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // Fondo
    painter.fillRect(rect(), QColor(deadColor));

    // Fondo - usa el tamaño completo del widget
    painter.fillRect(rect(), QColor(deadColor));

    // Calcular el tamaño de celda basado en el tamaño actual del widget
    // Esto permite escalar si el widget cambia de tamaño
    float dynamicCellWidth = (float)width() / gridSize;
    float dynamicCellHeight = (float)height() / gridSize;

    // Células vivas
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (grid[i][j]) {
                painter.fillRect(i * dynamicCellWidth, j * dynamicCellHeight,
                                 dynamicCellWidth, dynamicCellHeight, QColor(aliveColor));
            }
        }
    }

    // Cuadrícula
    painter.setPen(QColor(gridColor));
    for (int i = 0; i <= gridSize; ++i) {
        painter.drawLine(i * dynamicCellWidth, 0, i * dynamicCellWidth, height());
        painter.drawLine(0, i * dynamicCellHeight, width(), i * dynamicCellHeight);
    }
}

void GameOfLife::mousePressEvent(QMouseEvent *event) {
    float cellWidth = (float)width() / gridSize;
    float cellHeight = (float)height() / gridSize;

    int x = event->pos().x() / cellWidth;
    int y = event->pos().y() / cellHeight;

    if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
        changeCell(x, y);
        update();
    }
}

void GameOfLife::nextGeneration() {
    auto newGrid = grid;
    for (int i = 0; i < gridSize; ++i)
        for (int j = 0; j < gridSize; ++j) {
            int neighbors = countNeighbors(i, j, mapa);
            if(grid[i][j])//en caso de estar vivo
                newGrid[i][j] = (neighbors == 2 || neighbors == 3);
            //solo permanece asi si tiene 2 o 3 vecinos
            else//en caso de estar muerto
                newGrid[i][j] = (neighbors == 3);
            //solo revive si teiene 3 vecinos
        }

    grid = newGrid;
    update();
}

int GameOfLife::countNeighbors(int x, int y, int mundo) {
    int count = 0, nx, ny;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            switch (mundo) {
            case 1://Mundo cuadrado
                nx = x + i, ny = y + j;
                if (nx >= 0 && nx < gridSize && ny >= 0 && ny < gridSize)
                    if (grid[nx][ny]) count++;
                break;
            case 2://Mundo Toroidal
                nx = (x + i + gridSize) % gridSize , ny = (y + j + gridSize) % gridSize;
                if (grid[nx][ny]) count++;
                break;
            }
        }
    }
    return count;
}

void GameOfLife::changeCell(int x, int y) {
    grid[x][y] = !grid[x][y];
}

void GameOfLife::pauseGen(bool bnd){
    if (bnd) timer->start(timeGen);
    else timer->stop();
}

void GameOfLife::naveGen(int fila, int columna, int sentido){
    // Comprobar que la fila y columna están dentro de los límites
    if (fila < 0 || fila + 9 > gridSize || columna < 0 || columna + 36 > gridSize) {
        qDebug() << "Posición de glider fuera de los límites";
        return;
    }
    int planeadores[9][36] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
        {1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    switch(sentido){
    case 0:
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 36; ++j)
                grid[fila + i][columna + j] = planeadores[i][j];
        break;
    case 1:
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 36; ++j) {
                // rotación 90°: nueva[f][c] = original[8 - f][c]
                int r = j;          // pasa a filas
                int c = 8 - i;      // pasa a columnas
                grid[fila + r][columna + c] = planeadores[i][j];
            }
        }
        break;
    case 2:
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 36; ++j)
                // rotación 180°: nueva[f][c] = original[8 - f][35 - c]
                grid[fila + (8 - i)][columna + (35 - j)] = planeadores[i][j];
        break;
    case 3:
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 36; ++j) {
                // rotación 270°: nueva[f][c] = original[f][35 - f]
                int r = 35 - j;
                int c = i;
                grid[fila + r][columna + c] = planeadores[i][j];
            }
        }
        break;
    }
    update();
    pauseGen(false);
}
void GameOfLife::setGridSize(int newSize) {
    gridSize = newSize;
    grid.resize(gridSize, std::vector<bool>(gridSize, false));
    adjustSizeToGrid();
    update();
}
int GameOfLife::getCellSize(){return cellSize;}
void GameOfLife::setCellSize(int newSize){
    cellSize = newSize;
}
int GameOfLife::getTimeGen(){ return timeGen;}
void GameOfLife::setTimeGen(int newTime){
    timeGen = newTime;
    timer->stop();
    timer->start(timeGen);
}
void GameOfLife::changePause(){
    running = !running;
    pauseGen(running);
}
int GameOfLife::getMapa(){return mapa;}
void GameOfLife::setMapa(int newMapa){
    mapa = newMapa;
}
