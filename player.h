#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QRect>
#include <QTimer>
#include <QPixmap>

class Player : public QObject {
    Q_OBJECT
public:
    Player(QObject *parent, int x, int y);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();

    void setRect(const QRect &newRect);

    QRect getRect() const;
    QPixmap getPixmap() const;

signals:
    void positionChanged();

private:
    QRect rect;
    QPixmap pixmap;
    int speed;
    QTimer *timer;
    bool movingLeft, movingRight, movingUp, movingDown;
    int dx, dy;

private slots:
    void updatePosition();
};

#endif // PLAYER_H
