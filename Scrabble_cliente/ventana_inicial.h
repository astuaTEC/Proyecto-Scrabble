#ifndef VENTANA_INICIAL_H
#define VENTANA_INICIAL_H

#include <QMainWindow>

namespace Ui {
class ventana_inicio;
}

class ventana_inicial : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventana_inicial(QWidget *parent = nullptr);
    ~ventana_inicial();

private slots:
    void on_salir_clicked();

    void on_crearJuego_clicked();

    void on_unirseJuego_clicked();





private:
    Ui::ventana_inicio *ui;
};

#endif // VENTANA_INICIAL_H
