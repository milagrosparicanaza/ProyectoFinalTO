#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "player.h"
#include "gameobject.h"
#include <QList>
#include "fish.h"
#include "trash.h"
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow {
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);  // Constructor
    ~GameWindow();  // Destructor

public slots:
    void spawnFish();  // Genera un pez
    void handleFishOutOfScreen(Fish *fish);  // Maneja peces fuera de pantalla
    void spawnTrash();  // Genera basura
    void handleTrashOutOfScreen(Trash *trash);  // Maneja basura fuera de pantalla
    void handleObjectCollision(GameObject* object);  // Maneja colisiones de objetos
    void updateScore();  // Actualiza el puntaje

protected:
    void paintEvent(QPaintEvent *event) override;  // Maneja el evento de pintura
    void keyPressEvent(QKeyEvent *event) override;  // Maneja la presión de teclas
    void keyReleaseEvent(QKeyEvent *event) override;  // Maneja la liberación de teclas
    void showEvent(QShowEvent *event) override;  // Maneja el evento de mostrar
    void resizeEvent(QResizeEvent *event) override;  // Maneja el evento de redimensionar

private slots:
    void updateGameObjects();  // Actualiza objetos del juego

private:
    Ui::GameWindow *ui;  // Interfaz de usuario
    Player *player;  // Jugador
    bool playerPositioned;  // Indica si el jugador está posicionado
    QList<GameObject *> gameObjects;  // Lista de objetos del juego
    int trashCollected;  // Cuenta basuras recogidas
    int trashMissed;  // Cuenta basuras perdidas
    QLabel *labelTrashCollected;  // Etiqueta para basuras recogidas
    QLabel *labelTrashMissed;  // Etiqueta para basuras perdidas
    QPushButton *closeButton;
};

#endif // GAMEWINDOW_H
