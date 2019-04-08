#include "juego.h"
#include "socketserver.h"

auto server= SocketServer::getInstance();

Juego::Juego()
{

}

 void Juego::iniciarJuego()
{
    server = SocketServer::getInstance();
       pthread_t hiloServer;
       pthread_create(&hiloServer,0,serverRun,NULL);
       pthread_detach(hiloServer);

    while (1) {
           string mensaje;
           cin >> mensaje;
           server->setMensaje(mensaje.c_str());
       }

    //server->setMensaje(d->repartir(3).c_str());


    delete server;


}
static void * serverRun(void *)
{
    try{
        server->run();
    }catch(string ex)
    {
        cout << ex;
    }

   pthread_exit(NULL);
}
