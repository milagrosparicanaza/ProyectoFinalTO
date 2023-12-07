// GameWindow.cpp
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPainter>
#include <QKeyEvent>

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
    , player(new Player(this, 50, 50, 100, 100))
{
    ui->setupUi(this);
    this->showMaximized();

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
    painter.setBrush(Qt::blue);
    painter.drawRect(player->getRect());
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
