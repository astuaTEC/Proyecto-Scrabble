#ifndef INICIO_VENTANA_H
#define INICIO_VENTANA_H

#include <QWidget>

namespace Ui {
class inicio_ventana;
}
/**
 * @brief The inicio_ventana class Es la interfaz grafica del menu principal donde se puede ir a crear un juego
 * o unirse a uno ya creado,
 */
class inicio_ventana : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief inicio_ventana Constructor.
     * @param parent
     */
    explicit inicio_ventana(QWidget *parent = nullptr);
    ~inicio_ventana();

private slots:
    /**
     * @brief on_crearJuego_clicked Evento cuando se le da click en crear un juego.
     */
    void on_crearJuego_clicked();
    /**
     * @brief on_unirseJuego_clicked Evento cuando se le da click en unirse a un juego.
     */
    void on_unirseJuego_clicked();
    /**
     * @brief on_salir_clicked Evento cuando se le da click en salir.
     */
    void on_salir_clicked();

private:
    Ui::inicio_ventana *ui;
};

#endif // INICIO_VENTANA_H
