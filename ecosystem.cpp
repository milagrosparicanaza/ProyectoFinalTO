#include "ecosystem.h"
#include <QPainter>

// Constructor: carga la imagen del ecosistema
Ecosystem::Ecosystem() {
    background.load(":/img/images/ecosystem.png"); // Carga imagen de fondo
}

// Dibuja el ecosistema en un QPainter dado
void Ecosystem::draw(QPainter *painter, const QRect& rect) {
    // Escala el fondo para ajustarse al rectángulo manteniendo la relación de aspecto
    QPixmap scaledBg = background.scaled(rect.size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    // Calcula coordenadas para centrar la imagen en el rectángulo
    int x = (rect.width() - scaledBg.width()) / 2;
    int y = (rect.height() - scaledBg.height()) / 2;

    // Crea un nuevo rectángulo centrado para la imagen
    QRect centeredRect(x, y, scaledBg.width(), scaledBg.height());

    // Ajusta x si la imagen es más ancha que la ventana
    if (scaledBg.width() > rect.width()) {
        centeredRect.moveLeft(0);
    }

    // Ajusta y si la imagen es más alta que la ventana
    if (scaledBg.height() > rect.height()) {
        centeredRect.moveTop(0);
    }

    // Dibuja la imagen escalada en el rectángulo centrado
    painter->drawPixmap(centeredRect, scaledBg);
}
