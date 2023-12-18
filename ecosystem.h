#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H

#include <QPixmap>

class Ecosystem {
public:
    Ecosystem();
    void draw(QPainter *painter, const QRect& rect); // Función para dibujar el ecosistema

private:
    QPixmap background; // QPixmap para almacenar la imagen del ecosistema
};

#endif // ECOSYSTEM_H
