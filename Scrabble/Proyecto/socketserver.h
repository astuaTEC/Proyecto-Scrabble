#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H


#include "jugador.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <Estructuras/List.h>


using namespace std;

struct dataSocket{
    int descriptor;
    sockaddr_in info;
};

class SocketServer
{
public:
    Jugador jugador1;
    Jugador jugador2;
    Jugador jugador3;
    Jugador jugador4;

    string nombre;

    int contador;

    void run();
    void setMensaje(const char *msn);
    void setMensaje(int);
    void setMensaje(int, string, bool);
    void eliminar();
    static SocketServer* getInstance();
    void enviarNombres();
    void setClave(int);
    void asignarPuntajes(int n, int);

    void actualizarTurno();

    vector<int> clientes;
    vector<string> nombres;
    vector<int> puntuaciones;

    int nJugadores;
    void setJugadores(int);
    int getClave();



private:
    int descriptor;
    sockaddr_in info;
    int clave;
    bool crear_Socket();
    bool ligar_kernel();
    static SocketServer* instance;
    SocketServer();
    static void * controladorCliente(void *obj);
    //List<Cliente> clientes2;

};

#endif // SOCKETSERVER_H

