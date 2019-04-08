#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "Converter.h"
#include "socketcliente.h"

class Controlador : public QObject
{

    Q_OBJECT
public:
    Controlador();
    Converter *converter;

    void IniciarConexion();
    void setConectado(bool c);
    bool getConectado();
      void sendMensaje(string);

private slots:
    void RecibirMensaje(QString mensaje);



private:
    //atributo para verificar si el cliente está conectado
    bool conectado;

    SocketCliente *conexion;
};

#endif // CONTROLADOR_H
