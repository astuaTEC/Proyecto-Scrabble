//
// Created by saymon on 25/03/19.
//

#include "Converter.h"
#include <include/rapidjson/document.h>
#include <Tablero/Tablero.h>
#include <vector>
#include <include/rapidjson/fwd.h>
#include <include/rapidjson/stringbuffer.h>
#include <include/rapidjson/writer.h>
#include <thread>
#include <socketserver.h>
#include <QList>
#include <sys/socket.h>


extern SocketServer *server;
using namespace std;
using namespace rapidjson;

Converter* Converter::instance = 0;
/**
 * @brief Converter::getInstance
 * @return instancia de converter la cual es un singleton
 */
Converter* Converter::getInstance()
{
    if (instance == 0)
    {
        instance = new Converter();
    }

    return instance;
}
/**
 * @brief Converter::Converter
 * constructorde converter
 */
Converter::Converter() {
}

/**
 * @brief Converter::JsonToFicha
 * @param json el objeto json recibido del sockets
 * @param jugador el indentificador de jugador
 * convierte el json a fichas para trabajarlas
 */
void Converter::JsonToFicha(const char* json, int jugador) {
    Document document;
    auto tablero = Tablero::getInstance();

    int resultado = 0;
    int horizontal=0;
    int vertical=0;
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    document.Parse(json);

    assert(document.HasMember("palabra"));
    assert(document["palabra"].IsArray());
    const Value& a = document["palabra"];


    for (auto& v : a.GetArray()){
        pasarFicha(v.GetString());
    }
    vertical= tablero->recorrerVertical(fila, columna);
    horizontal = tablero->recorrerHorizontal(fila, columna);

    if(vertical !=0){
        resultado = vertical;
    }
    else if(horizontal!=0){
        resultado= horizontal;
    }
    writer.StartObject();
    writer.Key("resultado");
    writer.Int(resultado);
    writer.EndObject();
    server->asignarPuntajes(jugador, resultado);
    if(resultado != 0){
       server->setMensaje(jugador, json, false);
       server->setMensaje(jugador, s.GetString(), true);
       server->actualizarTurno();

    }
    else{

    server->setMensaje(jugador, s.GetString(), true);
    //server->actualizarTurno();
    }
}
/**
 * @brief Converter::pasarFicha
 * @param json objeto json
 * accede a una ficha desde el json y la coloca en el tablero logico
 */

void Converter:: pasarFicha(const char* json){
    auto tablero = Tablero::getInstance();
    Document document;
    int valor;
    string letra;
    int col;
    int fil;

    document.Parse(json);

    assert(document.HasMember("letra"));
    assert(document["letra"].IsString());
    cout<< "letra: " << document["letra"].GetString() << endl;
    letra = document["letra"].GetString();

    assert(document.HasMember("valor"));
    assert(document["valor"].IsInt());
    cout<< "valor: "<< document["valor"].GetInt() << endl;
    valor = document["valor"].GetInt();


    assert(document.HasMember("fila"));
    assert(document["fila"].IsInt());
    cout<< "valor: "<< document["fila"].GetInt() << endl;
    fil = document["fila"].GetInt();

    assert(document.HasMember("columna"));
    assert(document["columna"].IsInt());
    cout<< "valor: "<< document["columna"].GetInt() << endl;
    col= document["columna"].GetInt();

   tablero->agregar(fil,col,letra,valor);
   fila = fil;
   columna = col;



}
/**
 * @brief Converter::FichasToJson
 * @param pList lista de fichas
 * @return retorna un json para enviar por sockets
 */
const char* Converter:: FichasToJson(QList<Ficha*> pList){
    StringBuffer a;
    Writer<StringBuffer> writer2(a);

    writer2.StartObject();
    writer2.Key("fichas");
    writer2.StartArray();

    for(int i=0; i < pList.size(); i++) {
        Ficha *ficha= pList[i];
        StringBuffer s;
        Writer<StringBuffer> writer(s);
        writer.StartObject();
        writer.Key("letra");
        if(ficha->getLetra() != "")
            writer.String(ficha->getLetra().c_str());
        writer.Key("valor");
        writer.Int(ficha->getValor());
        writer.EndObject();
        writer2.String(s.GetString());
    }

    writer2.EndArray();
    writer2.EndObject();

    return a.GetString();

}
/**
 * @brief Converter::funcionGeneral
 * @param json objeto json recibido de el cliente el cual se parseara
 * @param jugador descritor del cliente que envio el json
 * verifica cada keys para ver que funcion debe llamar en cada posible caso de datos recibidos
 */
void Converter:: funcionGeneral(const char* json, int jugador){

    Document document;

    document.Parse(json);

    if(document.HasMember("palabra")){
        JsonToFicha(json, jugador);
    }
    else if(document.HasMember("inicial")){
       const Value& a = document["inicial"];
       for (auto& v : a.GetArray())
            generarClave(v.GetString());
    }

    else if(document.HasMember("unirse")){
        verificarClave(document["unirse"].GetInt(), jugador, document["nombre"].GetString());

    }
    else if(document.HasMember("reparta")){
        verificarCompartir();
    }
}
/**
 * @brief Converter::validarPalabra
 * @param json objeto json que trae la palabra o conjunto de letras de un cliente especifico
 * valida en ellemario si esa palabra existe
 */
void Converter:: validarPalabra(const char* json){
    Document document;

    document.Parse(json);

    assert(document.HasMember("palabra"));
    assert(document["palabra"].IsArray());
    const Value& a = document["palabra"];

    for (auto& v : a.GetArray())
        pasarFicha(v.GetString());
    }
/**
 * @brief Converter::verificarClave
 * @param clave clave enviada por el cliente
 * @param jugador jugador que envio la clave
 * @param nombre nombre del jugador el cual se unio y envio la clave
 * verifica con la clave generada por el creador de partidas
 */
void Converter:: verificarClave(int clave, int jugador, string nombre){
    if(clave != server->getClave() || server->nJugadores<server->clientes.size()){
        StringBuffer s;
        Writer<StringBuffer> writer(s);
        writer.StartObject();
        writer.Key("respuesta");
        writer.Bool(false);
        writer.EndObject();
        server->setMensaje(jugador, s.GetString(), true);
        for(int i=0; i<server->clientes.size(); i++){
            if(server->clientes[i]==jugador){
                server->clientes.erase(server->clientes.begin()+i);
                server->nombres.erase(server->nombres.begin()+i);
                server->puntuaciones.erase(server->puntuaciones.begin()+i);
                break;
            }
        }
    }
    else {
        StringBuffer s2;
        Writer<StringBuffer> writer(s2);
        writer.StartObject();
        writer.Key("respuesta");
        writer.Bool(true);
        writer.EndObject();

        server->nombres.push_back(nombre);
        server->puntuaciones.push_back(0);
        server->setMensaje(jugador,s2.GetString(), true);


        enviar();

    }

}
/**
 * @brief Converter::enviar
 * creada para enviar todas las fichas a todos los jugadores mientras este el maximo
 */
void Converter::enviar(){
    server->setMensaje(server->nJugadores);


}

void Converter:: generarClave(const char* clave){
    Document document;
    document.Parse(clave);

    assert(document.HasMember("nombre"));
    assert(document["nombre"].IsString());
    server->nombres.push_back(document["nombre"].GetString());

    server->nombre = document["nombre"].GetString();

    assert(document.HasMember("jugadores"));
    assert(document["jugadores"].IsInt());
    server->setJugadores(document["jugadores"].GetInt());


    srand(time(NULL));
    int num = 99999 + rand() % (999999);


    server->setClave(num);
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.Key("clave");
    writer.Int(num);
    writer.EndObject();

    server->setMensaje(s.GetString());
}
/**
 * @brief Converter::verificarCompartir
 * verifica si esta la partida llena para enviar las fichas a cada jugador
 */
void Converter::verificarCompartir(){
    if (server->nJugadores==server->clientes.size()){
        server->setMensaje(server->nJugadores);
    }
}
