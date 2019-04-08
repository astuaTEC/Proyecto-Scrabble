#ifndef UNIRSE_JUEGO_H
#define UNIRSE_JUEGO_H

#include <QWidget>
#include "Converter.h"
#include "socketcliente.h"
#include "juego.h"

namespace Ui {
class unirse_juego;
}
/**
 * @brief The unirse_juego class proporciona una interfaz para cuando se va a unir a una nueva partida.
 */
class unirse_juego : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief unirse_juego Constructor.
     * @param parent
     */
    explicit unirse_juego(QWidget *parent = nullptr);
    ~unirse_juego();

     Converter *converter;
     bool estaConectado;
     /**
      * @brief iniciarConexion Inicializa los sockets.
      */
     void iniciarConexion();
     /**
      * @brief iniciarJuego Direcciona al juego principal.
      */
     void iniciarJuego();
     int cont;

     QString json;


private slots:

     /**
     * @brief on_botonVolver_clicked Evento del botom volver.
     */
    void on_botonVolver_clicked();
    /**
     * @brief RecibirMensaje Cuando me llega un mensaje desde el servidor.
     * @param mensaje El mensaje.
     */
    void RecibirMensaje(QString mensaje);
    /**
     * @brief sendMensaje Enviar un mensaje al servidor.
     */
    void sendMensaje(string);
    /**
     * @brief on_botonUnirse_2_clicked Cuando le damos click al boton unirse.
     */
    void on_botonUnirse_2_clicked();



private:
    Ui::unirse_juego *ui;

    //atributos privados
    SocketCliente *conexion;

};

#endif // UNIRSE_JUEGO_H
