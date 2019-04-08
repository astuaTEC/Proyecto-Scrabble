#include <iostream>
#include <stdlib.h>
#include "Tablero/Tablero.h"
#include "Dealer/Dealer.h"
#include <locale.h>
#include <vector>
#include <socketserver.h>


using namespace std;


SocketServer *server;

void * serverRun(void *)
{
    try{
        server->run();
    }catch(string ex)
    {
        cout << ex;
    }

   pthread_exit(NULL);
}
bool juego=true;
int main(){

    server= SocketServer::getInstance();
    auto tablero = Tablero::getInstance();
    server = SocketServer::getInstance();
    auto d =Dealer::getInstance();
    pthread_t hiloServer;
       pthread_create(&hiloServer,0,serverRun,NULL);
       pthread_detach(hiloServer);

    while (juego) {
           string mensaje;
           //cin >> mensaje;
           //server->setMensaje(mensaje.c_str());
       }

    delete server;
    tablero->limpiar();

    return 0;
}
