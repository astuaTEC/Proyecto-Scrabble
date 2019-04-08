#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <QObject>
#include <arpa/inet.h>

using namespace std;
/**
 * @brief The SocketCliente class Permite crear y mantener la conexion con el servidor.
 */
class SocketCliente: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief SocketCliente Constructor.
     */
    SocketCliente();
    bool connectar();
    /**
     * @brief setMensaje envia un mensaje directo al servidor.
     * @param msn El mensaje.
     */
    void setMensaje(const char *msn);
private:
    int descriptor;
    sockaddr_in info;
    static void * controlador(void *obj);
signals:
    /**
     * @brief NewMensaje Me avisa si me ha llegado un nuevo mensaje desde el servidor.
     * @param msn El mensaje.
     */
    void NewMensaje(QString msn);
};
#endif // SOCKETCLIENTE_H
