#ifndef CREAR_JUEGO_H
#define CREAR_JUEGO_H
#include "socketcliente.h"
#include <QWidget>
#include "Converter.h"
#include "juego.h"

namespace Ui {
class crear_juego;
}
/**
 * @brief The crear_juego class La ventana en donde se crea una nueva partida.
 */
class crear_juego : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief crear_juego Constructor.
     * @param parent
     */
    explicit crear_juego(QWidget *parent = nullptr);

    ~crear_juego();
    Converter *converter;
    bool estaConectado;
    /**
     * @brief iniciarConexion Inicializa los sockets.
     */
    void iniciarConexion();
    /**
     * @brief iniciarJuego Redirecciona al juego.
     */
    void iniciarJuego();

    QString json;

    bool paseAlOtro;

private slots:
    /**
     * @brief on_botonVolver_clicked Cuando se pulsa un boton.
     */
    void on_botonVolver_clicked();
    /**
     * @brief RecibirMensaje Cuando llega un mensaje del socket.
     * @param mensaje El mensaje.
     */
    void RecibirMensaje(QString mensaje);
    /**
     * @brief sendMensaje Envia mensajes al servidor.
     */
    void sendMensaje(string);
    /**
     * @brief on_botonCrear_clicked Cuando se le da click al boton.
     */
    void on_botonCrear_clicked();



private:
    Ui::crear_juego *ui;


    //atributos privados
    SocketCliente *conexion2;
};

#endif // CREAR_JUEGO_H
