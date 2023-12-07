#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QRect>
#include <QTimer>

class Player : public QObject {
    Q_OBJECT
public:
    Player(QObject *parent, int x, int y, int width, int height);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();

    QRect getRect() const;

signals:
    void positionChanged();

private:
    QRect rect;
    int speed;
    QTimer *timer;
    bool movingLeft, movingRight, movingUp, movingDown;
    int dx, dy;

private slots:
    void updatePosition();
};

#endif // PLAYER_H
