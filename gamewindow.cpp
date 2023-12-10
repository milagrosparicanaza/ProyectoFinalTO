// GameWindow.cpp
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPainter>
#include <QKeyEvent>

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
    , playerPositioned(false)
{
    ui->setupUi(this);
    this->showMaximized();

    player = new Player(this, -100, -100);

    // Conectar la señal positionChanged de player con el slot update() de la ventana
    connect(player, &Player::positionChanged, this, QOverload<>::of(&GameWindow::update));
}

GameWindow::~GameWindow()
{
    delete ui;
    delete player;
}

void GameWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    QPainter painter(this);

    // Asegúrate de que el player solo se dibuje si ha sido posicionado correctamente
    if (playerPositioned) {
        // Si player tiene un pixmap válido, dibújalo
        if (!player->getPixmap().isNull()) {
            painter.drawPixmap(player->getRect(), player->getPixmap());
        } else {
            // Si no, dibuja un rectángulo como marcador de posición
            painter.setBrush(Qt::blue);
            painter.drawRect(player->getRect());
        }
    }
    // Si playerPositioned es falso, no se dibuja nada, evitando que el player aparezca en (0, 0)
}


void GameWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event); // Asegúrate de llamar al método base primero

    // Retrasa la centralización del jugador para asegurarte de que la ventana esté completamente maximizada
    QTimer::singleShot(100, this, [this]() { // Puedes ajustar el tiempo si es necesario
        if (!playerPositioned) {
            // Asegúrate de que el tamaño de la ventana esté disponible
            int centerX = this->width() / 2;
            int centerY = this->height() / 2;

            // Asigna la posición inicial del jugador
            int pixmapWidth = player->getPixmap().width();
            int pixmapHeight = player->getPixmap().height();
            player->setRect(QRect(centerX - pixmapWidth / 2, centerY - pixmapHeight / 2, pixmapWidth, pixmapHeight));
            playerPositioned = true;
            update();
        }
    });
}

void GameWindow::resizeEvent(QResizeEvent *event)
{
    // Guarda las dimensiones antiguas
    int oldWidth = event->oldSize().width();
    int oldHeight = event->oldSize().height();

    // Nuevas dimensiones
    int newWidth = this->width();
    int newHeight = this->height();

    // Si es la primera vez que se llama resizeEvent, no hay dimensiones antiguas válidas,
    // así que simplemente llama al método base y retorna
    if (oldWidth == -1 || oldHeight == -1) {
        QMainWindow::resizeEvent(event);
        return;
    }

    // Calcular la proporción de cambio en la anchura y altura
    float widthRatio = static_cast<float>(newWidth) / static_cast<float>(oldWidth);
    float heightRatio = static_cast<float>(newHeight) / static_cast<float>(oldHeight);

    // Obtener la posición actual del Player
    QRect currentRect = player->getRect();

    // Calcular la nueva posición basada en la proporción de cambio
    int newX = static_cast<int>(currentRect.x() * widthRatio);
    int newY = static_cast<int>(currentRect.y() * heightRatio);

    // Asigna la nueva posición proporcional del jugador manteniendo el tamaño original
    player->setRect(QRect(newX, newY, currentRect.width(), currentRect.height()));

    // Llama al método base
    QMainWindow::resizeEvent(event);

    // Fuerza la ventana a repintarse con el jugador en la nueva posición
    update();
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat()) {
        switch(event->key()) {
        case Qt::Key_Left:
        case Qt::Key_A: player->moveLeft(); break;
        case Qt::Key_Right:
        case Qt::Key_D: player->moveRight(); break;
        case Qt::Key_Up:
        case Qt::Key_W: player->moveUp(); break;
        case Qt::Key_Down:
        case Qt::Key_S: player->moveDown(); break;
        }
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat()) {
        switch(event->key()) {
        case Qt::Key_Left:
        case Qt::Key_A: player->stopLeft(); break;
        case Qt::Key_Right:
        case Qt::Key_D: player->stopRight(); break;
        case Qt::Key_Up:
        case Qt::Key_W: player->stopUp(); break;
        case Qt::Key_Down:
        case Qt::Key_S: player->stopDown(); break;
        }
    }
}
