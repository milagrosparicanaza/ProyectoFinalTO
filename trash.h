#ifndef TRASH_H
#define TRASH_H

#include "gameobject.h"

class Trash : public GameObject {
    Q_OBJECT

public:
    explicit Trash(QObject *parent = nullptr);  // Constructor para el objeto Trash
    void updatePosition() override;  // Actualiza posición, sobrescribe método de GameObject

signals:
    void trashOutOfScreen(Trash *trash);  // Señal emitida cuando la basura sale de pantalla
};

#endif // TRASH_H
