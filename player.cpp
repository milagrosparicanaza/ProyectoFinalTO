#include "player.h"

Player::Player(QObject *parent, int x, int y)
    : QObject(parent), speed(1),
    movingLeft(false), movingRight(false), movingUp(false), movingDown(false),
    dx(0), dy(0)
{
    pixmap.load(":/img/images/SubmarinoRobotico.png");
    rect = QRect(x, y, pixmap.width(), pixmap.height());

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

void Player::setRect(const QRect &newRect) {
    rect = newRect;
    emit positionChanged();
}

QPixmap Player::getPixmap() const {
    return pixmap;
}
