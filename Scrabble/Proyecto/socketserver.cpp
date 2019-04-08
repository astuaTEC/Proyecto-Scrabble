#include "socketserver.h"
#include <Dealer/Dealer.h>
#include <Converter/Converter.h>
#include <QDebug>
#include <include/rapidjson/fwd.h>
#include <include/rapidjson/stringbuffer.h>
#include <include/rapidjson/writer.h>


SocketServer* SocketServer::instance = 0;
/**
 * @brief SocketServer::getInstance
 * @return retorna la instancia de socketserver siendo este un singleton
 */
SocketServer* SocketServer:: getInstance(){
    if (instance == 0)
        {
            instance = new SocketServer();
        }

        return instance;

}
/**
 * @brief SocketServer::SocketServer
 */
SocketServer::SocketServer()
{
nJugadores= 1;
contador=0;
}
/**
 * @brief SocketServer::setJugadores
 * @param n integer con el numero de jugadores en partida
 */
void SocketServer:: setJugadores(int n){
    this->nJugadores = n;
}
/**
 * @brief SocketServer::setClave
 * @param clave numero de clave creada aleatoriamente
 */
void SocketServer::setClave(int clave){
    this->clave= clave;
}
/**
 * @brief SocketServer::asignarPuntajes
 * @param n cantidad de jugadores en partidas
 * @param puntos puntos obtenidos por la palabra generada e cliente
 */
void SocketServer::asignarPuntajes(int n, int puntos)
{
    for(int i=0; i<clientes.size();i++){
        if(clientes[i] == n){
            puntuaciones[i] += puntos;
        }
    }
    StringBuffer a;
    Writer<StringBuffer> writer2(a);

    writer2.StartObject();
    writer2.Key("puntaje");
    writer2.StartArray();
    for(int i=0; i<nJugadores;i++){
        string nombre = nombres[i];
        int puntos = puntuaciones[i];
        StringBuffer s;
        Writer<StringBuffer> writer(s);
        writer.StartObject();
        writer.Key("nombre");
        writer.String(nombre.c_str());
        writer.Key("puntos");
        writer.Int(puntos);
        writer.EndObject();
        writer2.String(s.GetString());
    }
    writer2.EndArray();
    writer2.EndObject();

    setMensaje(a.GetString());

}
/**
 * @brief SocketServer::actualizarTurno
 * actuliza el turno de jugadores para ver a quien le corresponde
 */
void SocketServer::actualizarTurno()
{
    if(contador== nombres.size()-1){
        contador=0;
    }
    nombre = nombres[contador+1];
    StringBuffer a;
    Writer<StringBuffer> writer(a);

    writer.StartObject();
    writer.Key("turno");
    writer.String(nombre.c_str());
    writer.EndObject();

    setMensaje(a.GetString());



}
/**
 * @brief SocketServer::getClave
 * @return retorna la clave del juego creado por creador de partida
 */
int SocketServer:: getClave(){
    return this->clave;
}
/**
 * @brief SocketServer::crear_Socket
 * @return falso si el descriptor del socket no se puede crear
 */
bool SocketServer::crear_Socket()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);


    if(descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(4050);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    return true;
}
/**
 * @brief SocketServer::ligar_kernel
 * @return true si se puede ligar el kernel o false si no se lo permite
 */
bool SocketServer::ligar_kernel()
{
    if((bind(descriptor,(sockaddr *)&info,(socklen_t)sizeof(info))) < 0)
        return false;

    listen(descriptor,4);
    return true;
}
/**
 * @brief SocketServer::run
 * se encarga de generar la conexion recibiendo los clientes y generando el servidor y las estructuras
 * para cada cliente trabajando por hilos
 */
void SocketServer::run()
{

    if(!crear_Socket())
        throw string("Error al crear el socket");
    if(!ligar_kernel())
        throw string("Error al  ligar kernel");

    while (true) {
        cout << "Esperando al cliente"<<endl;
        dataSocket *data=(struct dataSocket *)malloc(sizeof(dataSocket));
        socklen_t tam = sizeof(data->info);
        data->descriptor = accept(descriptor,(sockaddr*)&data->info,&tam);
        if(data->descriptor < 0)
            cout << "Error al acceptar al cliente"<<endl;
        else

        {
            cout << "Cliente aceptado"<<endl;
            clientes.push_back(data->descriptor);
            pthread_t hilo;
            pthread_create(&hilo,0,SocketServer::controladorCliente,(void *)data);
            pthread_detach(hilo);

            }
        }

    close(descriptor);
}

/**
 * @brief SocketServer::controladorCliente
 * @param obj objeto que contiene la estructura de cada cliente siendo este un puntero para no cambiar la direccion de memoria
 * escucha los mensajes de cada cliente y retorna
 * @return
 */

void * SocketServer::controladorCliente(void *obj)
{   auto converter = Converter::getInstance();

    dataSocket *data=(dataSocket*)obj;
    char *buffer=(char*)calloc(1024,sizeof (char));
    while (true) {
        string mensaje;
        while (1) {
            int bytes = recv(data->descriptor,buffer,1024,0);
            mensaje.append(buffer,bytes);
            if(bytes < 1024)
                break;
        }

        converter->funcionGeneral(mensaje.c_str(), data->descriptor);
        memset(buffer,0,sizeof (buffer));
    }

    close(data->descriptor);
    pthread_exit(NULL);
}
/**
 * @brief SocketServer::setMensaje
 * @param msn es un const char el cual es el mensaje a enviar a cada cliente
 */

void SocketServer::setMensaje(const char *msn)
{
    for(unsigned int i = 0 ; i < nJugadores ; i++){
        send(clientes[i],msn,strlen(msn),0);
    }

}
/**
 * @brief SocketServer::setMensaje
 * @param n cantidad de jugadores que estan conectados
 */

void SocketServer:: setMensaje(int n){
    auto *d = Dealer::getInstance();

    if (clientes.size()==n){

        for(int i=0; i<n;i++){
            string msn =d->repartir(n);
            send(clientes[i],msn.c_str(),strlen(msn.c_str()),0);
    }


}
}
/**
 * @brief SocketServer::setMensaje
 * @param jugador jugador que esta en partida, su descriptor
 * @param mensaje  mensaje que se va a enviar
 * @param operacion operacion siendo un booleano parar ver que se debe enviar a los jugadores
 */

void SocketServer:: setMensaje(int jugador, string mensaje, bool operacion){
    if(operacion){
        send(jugador,mensaje.c_str(),strlen(mensaje.c_str()),0);
    }
    else{
        for(int i=0; i<clientes.size(); i++){
            if(clientes[i]!=jugador){
            send(clientes[i],mensaje.c_str(),strlen(mensaje.c_str()),0);
            }
    }

}
}
/**
 * @brief SocketServer::eliminar
 * elimina los jugadores no aceptados, se equivocan en la clave
 */

void SocketServer::eliminar(){
    clientes.erase(clientes.begin()+clientes.size()-1);

}
/**
 * @brief SocketServer::enviarNombres
 * envia el nombre a cada jugador
 */
void SocketServer:: enviarNombres(){
    StringBuffer a;
    Writer<StringBuffer> writer2(a);

    writer2.StartObject();
    writer2.Key("nombres");
    writer2.StartArray();
    for(int i=0; i<nJugadores;i++){
        string nombre = nombres[i];
        StringBuffer s;
        Writer<StringBuffer> writer(s);
        writer.StartObject();
        writer.Key("nombre");
        writer.String(nombre.c_str());
        writer.EndObject();
        writer2.String(s.GetString());
    }
    writer2.EndArray();
    writer2.EndObject();
    if (clientes.size()==nJugadores){
    for(int i=clientes.size()-1;i>=0; i--){
        send(clientes[i],a.GetString(),strlen(a.GetString()),0);
    }}
}
