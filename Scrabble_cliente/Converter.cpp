#include "Converter.h"
#include <include/rapidjson/document.h>
#include <vector>
#include <include/rapidjson/fwd.h>
#include <include/rapidjson/stringbuffer.h>
#include <include/rapidjson/writer.h>
#include <string>
#include <string.h>
#include <QDebug>
#include <iostream>
#include <sys/socket.h>
#include "juego.h"

extern Juego *juego;
using namespace std;
//using namespace rapidjson;


Converter* Converter::instance = 0;

Converter* Converter::getInstance()
{
    if (instance == 0)
    {
        instance = new Converter();
    }

    return instance;
}

Converter::Converter() {
    claveGenerada = NULL;
    aceptado = false;
    llegaPuntajes = false;

    fichasRecibidas = false;
    llegaPalabra = false;
    llegaResultado = false;
    llegaTurno = false;



}

string Converter::repartaCartas()
{

    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.Key("reparta");
    writer.Bool(true);
    writer.EndObject();

    return s.GetString();
}


QList<Ficha*> Converter::JsonToFicha(const char* json) {
    //cout<<json<<endl;
    Document document;

    document.Parse(json);


    //////////////////////////////////
    //const char* a[] = document["fichas"].GetArray();
    ///////////////////////////////7

    qDebug()<< "antes antes del for";
    const Value& a = document["fichas"];
    assert(a.IsArray());
    qDebug()<<"antes del for";
    for (SizeType i = 0; i < a.Size(); i++){
        pasarFicha(a[i].GetString());
    }

    /*for (auto& v : a.GetArray()){

        pasarFicha(v.GetString());

     }*/
    qDebug()<<"sale del for";
    return fichas;
}

void Converter:: pasarFicha(const char* json){
    //auto tablero = Tablero::getInstance();
    Document document;
    int valor;
    string letra;

    document.Parse(json);


    //cout<< "letra: " << document["letra"].GetString() << endl;
    qDebug() << "letra: " << document["letra"].GetString();
    letra = document["letra"].GetString();


    //cout<< "valor: "<< document["valor"].GetInt() << endl;
    qDebug() << "valor: "<< document["valor"].GetInt();
    valor = document["valor"].GetInt();
    qDebug()<<valor;
    Ficha *ficha = new Ficha();
    ficha->setTexto(QString::fromStdString(letra));
    ficha->setTextoValor(valor);
    ficha->setEstaPuesta(false);
    ficha->setDueno("JUGADOR");
    ficha->setEsComodin(false);
    if(letra == "0"){
        ficha->setEsComodin(true);
        ficha->setTextoValor(0);
    }
    ficha->letrasVisibles();

    fichas.append(ficha);



}
string Converter:: PalabraToJson(QList<Ficha *> fichasJugadas){
    StringBuffer a;
    Writer<StringBuffer> writer2(a);

    writer2.StartObject();
    writer2.Key("palabra");
    writer2.StartArray();

    for(int i=0; i < fichasJugadas.size(); i++) {
        Ficha *ficha= fichasJugadas[i];
        StringBuffer s;

        Writer<StringBuffer> writer(s);
        writer.StartObject();
        writer.Key("letra");
        writer.String(ficha->getLetra().toStdString().c_str());
        writer.Key("valor");
        writer.Int(ficha->getValor());
        writer.Key("fila");
        writer.Int(ficha->getFila());
        writer.Key("columna");
        writer.Int(ficha->getColumna());
        writer.EndObject();
        writer2.String(s.GetString());

    }
    writer2.EndArray();
    writer2.EndObject();

    cout<< a.GetString()<< endl;

    //madar mensaje al servidor

    return a.GetString();

}

void Converter::mostrarClave(const char* json){


}

void Converter:: funcionGeneral(const char* json){

    Document document;

    document.Parse(json);

    if(document.HasMember("clave")){
        //assert(document["clave"].IsObject());
       claveGenerada = document["clave"].GetInt();
    }
    else if(document.HasMember("puntaje")){
        qDebug()<<"llegaron los puntajes";
        inicializarPuntajes(json);
        llegaPuntajes = true;
    }

    else if(document.HasMember("inicial")){
        generarClave(document["inicial"].GetInt());
    }
    else if(document.HasMember("fichas")){
        qDebug()<<"cambiando el valor de fichasRecibidas";
        fichasRecibidas = true;

    }
    else if(document.HasMember("respuesta")){
        if(document["respuesta"].GetBool()){
            qDebug() << "Entrando a has member aceptado";
            aceptado = true;
        }
    }
    else if(document.HasMember("palabra")){
        llegaPalabra = true;
    }
    else if(document.HasMember("resultado")){
        llegaResultado = true;
    }
    else if(document.HasMember("turno")){
        turnoDe = QString::fromStdString(document["turno"].GetString());
        llegaTurno = true;
    }

}

void Converter:: validarPalabra(const char* json){
    Document document;
    document.Parse(json);

    assert(document.HasMember("palabra"));
    assert(document["palabra"].IsArray());
    const Value& a = document["palabra"];

    for (auto& v : a.GetArray())
        pasarFicha(v.GetString());
        //printf("%s ", v.GetString());
}

void Converter:: verificarClave(int clave){

}

void Converter:: generarClave(int clave){

}

QList<Ficha *> Converter::jsonToPalabra(const char *json){
    Document document;

    document.Parse(json);

    const Value& a = document["palabra"];
    assert(a.IsArray());
    qDebug()<<"antes del for";
    for (SizeType i = 0; i < a.Size(); i++){
        pasarLetra(a[i].GetString());
    }
    return fichasActualizacion;


}

void Converter::pasarLetra(const char *letras){
    Document document;
    int valor;
    string letra;
    int fil;
    int col;

    document.Parse(letras);

    letra = document["letra"].GetString();

    valor = document["valor"].GetInt();

    fil =  document["fila"].GetInt();

    col=  document["columna"].GetInt();

    Ficha *ficha = new Ficha();
    ficha->setTexto(QString::fromStdString(letra));
    ficha->setTextoValor(valor);
    ficha->setEstaPuesta(false);
    ficha->setDueno("JUGADOR");
    ficha->setEsComodin(false);
    if(letra == "0"){
        ficha->setEsComodin(true);
        ficha->setTextoValor(0);
    }
    ficha->letrasVisibles();
    ficha->setColumna(col);
    ficha->setFila(fil);

    fichasActualizacion.append(ficha);


}

void Converter::inicializarPuntajes(const char *json){
    Document document;
    document.Parse(json);

    assert(document.HasMember("puntaje"));
    assert(document["puntaje"].IsArray());
    const Value& a = document["puntaje"];

    for (auto& v : a.GetArray())
        pasarNombres(v.GetString());
    //printf("%s ", v.GetString());
}

void Converter::pasarNombres(const char *n){
    Document document;

    string nombre;
    int puntaje;

    document.Parse(n);

    nombre = document["nombre"].GetString();
    puntaje = document["puntos"].GetInt();



    nombres.append(QString::fromStdString(nombre));
    puntajes.append((puntaje));





}


string Converter::convertirInicial(QString nombre, int jugadores){
    StringBuffer a;
    Writer<StringBuffer> writer2(a);

    writer2.StartObject();
    writer2.Key("inicial");
    writer2.StartArray();
    StringBuffer s;

    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.Key("nombre");
    writer.String(nombre.toStdString().c_str());
    writer.Key("jugadores");
    writer.Int(jugadores);
    writer.EndObject();
    writer2.String(s.GetString());
    writer2.EndArray();
    writer2.EndObject();


    cout << s.GetString()<< endl;
    string mensaje = a.GetString();
    //return s.GetString();
    return mensaje;

}

string Converter::unirse(int clave, string nombre){
    StringBuffer s;

    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.Key("unirse");
    writer.Int(clave);
    writer.Key("nombre");
    writer.String(nombre.c_str());


    writer.EndObject();

    return s.GetString();

}

int Converter::confirmarPalabra(const char *resultado){
    Document document;
    document.Parse(resultado);

    assert(document.HasMember("resultado"));
    assert(document["resultado"].IsInt());

    return document["resultado"].GetInt();

}

