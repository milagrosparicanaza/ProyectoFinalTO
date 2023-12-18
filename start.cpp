#include "start.h"
#include "ui_start.h"
#include "gamewindow.h"

// Constructor de la clase Start: inicializa la interfaz de usuario
Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start) {
    ui->setupUi(this);  // Configura la interfaz de usuario según la definición en el archivo .ui
}

// Destructor de Start: limpia los recursos de la interfaz de usuario
Start::~Start() {
    delete ui;  // Libera la memoria de la interfaz de usuario
}

// Manejador para el evento de clic en el botón de inicio
void Start::on_pushButton_clicked() {
    // Crea y muestra una instancia de GameWindow
    GameWindow *gameWindow = new GameWindow();
    gameWindow->show();

    // Cierra la ventana actual (Start)
    this->close();
}
