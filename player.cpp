#include "player.h"

Player::Player(QObject *parent, int x, int y, int width, int height)
    : QObject(parent), rect(x, y, width, height), speed(1),
    movingLeft(false), movingRight(false), movingUp(false), movingDown(false),
    dx(0), dy(0) // Inicializar dx y dy aquí
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::updatePosition);
    timer->start(10);
}

void Player::updatePosition() {
    dx = (movingRight - movingLeft) * speed;
    dy = (movingDown - movingUp) * speed;
    rect.translate(dx, dy);
    emit positionChanged();
}

void Player::moveLeft() { movingLeft = true; }
void Player::moveRight() { movingRight = true; }
void Player::moveUp() { movingUp = true; }
void Player::moveDown() { movingDown = true; }
void Player::stopLeft() { movingLeft = false; }
void Player::stopRight() { movingRight = false; }
void Player::stopUp() { movingUp = false; }
void Player::stopDown() { movingDown = false; }

QRect Player::getRect() const {
    return rect;
}
