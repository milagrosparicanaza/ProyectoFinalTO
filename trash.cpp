#include "trash.h"
#include <QRandomGenerator>
#include <QWidget>

// Constructor de Trash: inicializa un objeto Trash con posición y características aleatorias
Trash::Trash(QObject *parent)
    : GameObject(QRandomGenerator::global()->bounded(static_cast<QWidget*>(parent)->width()),
                 -50, // Inicia justo fuera de la vista en la parte superior
                 50, GameObject::Square, Qt::red, parent) {
    speed = 2;  // Establece velocidad de caída
}

// Actualiza la posición de Trash en cada frame
void Trash::updatePosition() {
    int dy = speed;  // Calcula el desplazamiento vertical
    rect.translate(0, dy);  // Mueve el objeto hacia abajo

    // Verifica si la basura ha salido de la pantalla
    if (rect.top() > parentWidget->height()) {
        emit trashOutOfScreen(this); // Emite señal si sale de la pantalla
    }
}
