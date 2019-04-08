#include "controlador.h"
#include <QDebug>
#include "socketcliente.h"
#include <iostream>
#include "Converter.h"
#include "socketcliente.h"


Controlador::Controlador(){
    //crear un objeto converter
    converter = Converter::getInstance();
    conexion = new SocketCliente;

    //inicializo el conectado
    conectado = false;


}

void Controlador::IniciarConexion(){
    if(conexion->connectar()){
        connect(conexion,SIGNAL(NewMensaje(QString)),SLOT(RecibirMensaje(QString)));
        setConectado(true);
        qDebug() << "Estamos conectados al servidor";
    }
    else{
    qDebug() << "Error al conectarse con el servidor";
    }


}

void Controlador::setConectado(bool c){
    conectado = c;

}

bool Controlador::getConectado(){
    return conectado;

}

void Controlador::RecibirMensaje(QString mensaje){
    qDebug() << mensaje;
    //ui->contra->setText(mensaje);
}

void Controlador::sendMensaje(string msj){
    conexion->setMensaje(msj.c_str());
}
