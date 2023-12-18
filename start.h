#ifndef START_H
#define START_H

#include <QWidget>

namespace Ui {
class Start;  // Clase de interfaz de usuario para la ventana de inicio
}

class Start : public QWidget {
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);  // Constructor de la ventana de inicio
    ~Start();  // Destructor

private slots:
    void on_pushButton_clicked();  // Manejador del clic en el botón de inicio

private:
    Ui::Start *ui;  // Interfaz de usuario
};

#endif // START_H
