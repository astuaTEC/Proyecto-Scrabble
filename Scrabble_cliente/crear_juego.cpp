#include "crear_juego.h"
#include "ui_crear_juego.h"
#include "inicio_ventana.h"
#include "socketcliente.h"
#include "juego.h"
#include <QDebug>
#include <iostream>
#include "Converter.h"

using namespace std;
extern Juego *juego;
crear_juego::crear_juego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::crear_juego)
{
    ui->setupUi(this);

    //colocamos la imagen de fondo
    QPixmap pix("/home/kevin/Descargas/fondo_opt.jpg");
    ui->imagen->setPixmap(pix);

    //cambiarle el color a los botones
    QPalette pal = ui->botonVolver->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
     ui->botonVolver->setAutoFillBackground(true);
     ui->botonVolver->setPalette(pal);
     ui->botonVolver->update();

    QPalette pal2 = ui->botonCrear->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::yellow));
      ui->botonCrear->setAutoFillBackground(true);
      ui->botonCrear->setPalette(pal2);
      ui->botonCrear->update();



      //cambiale el color a los textos
      QPalette palette = ui->cantidadJugadoresLabel->palette();
      palette.setColor(ui->cantidadJugadoresLabel->backgroundRole(), Qt::yellow);
      palette.setColor(ui->cantidadJugadoresLabel->foregroundRole(), Qt::yellow);
      ui->cantidadJugadoresLabel->setPalette(palette);

     QPalette palette2 = ui->nombreLabel->palette();
      palette2.setColor(ui->nombreLabel->backgroundRole(), Qt::yellow);
      palette2.setColor(ui->nombreLabel->foregroundRole(), Qt::yellow);
      ui->nombreLabel->setPalette(palette2);

      QPalette palette3 = ui->nombreLabel->palette();
       palette3.setColor(ui->nombreLabel->backgroundRole(), Qt::white);
       palette3.setColor(ui->nombreLabel->foregroundRole(), Qt::white);
       ui->contra->setPalette(palette3);


      //inicializar los widgets
      ui->nombre->setText("");
      ui->cantidadJugadores->setValue(0);


      //inicializar el boleano
      estaConectado = false;
      paseAlOtro = false;
      ui->nombreLabel->setPalette(palette2);

      //crear un objeto converter
      converter = Converter::getInstance();

      //CONFIGURACION DEL SOCKET
      conexion2 = new SocketCliente;

      //iniciar conexion
      iniciarConexion();


}

crear_juego::~crear_juego()
{
    delete ui;
}

void crear_juego::iniciarConexion(){

    if(conexion2->connectar()){
        connect(conexion2,SIGNAL(NewMensaje(QString)),SLOT(RecibirMensaje(QString)));
        estaConectado = true;
        qDebug() << "Estamos conectados al servidor";
    }

    else{
        qDebug() << "Error al conectarse con el servidor";
    }

}

void crear_juego::iniciarJuego(){
    qDebug()<<"Entrando a iniciar juego";
    juego->show();
    juego->GenerarListaConexion(json,conexion2,ui->nombre->text(),true);
    juego->Iniciar();


    close();

}

void crear_juego::on_botonVolver_clicked(){
    //volver a la ventana inicial
    inicio_ventana * ventanaInicial = new inicio_ventana();
    ventanaInicial->show();

    //cerramos esta ventana
    close();


}

void crear_juego::RecibirMensaje(QString mensaje){
    qDebug() << "mensaje en crear juego" <<mensaje;


    if(!converter->fichasRecibidas && converter->claveGenerada != NULL ){
        qDebug()<<"Entrando a 1";
        json = mensaje;
        iniciarJuego();

        converter->fichasRecibidas = true;
        paseAlOtro = true;
    }

    if(converter->claveGenerada == NULL){
        qDebug()<<"Entrando a 2";
        converter->funcionGeneral(QString(mensaje).toStdString().c_str());
    }


    if(converter->claveGenerada != NULL && !paseAlOtro){
        qDebug()<<"Entrando a 3";
        ui->contra->setText(QString::number(converter->claveGenerada));
    }





}

void crear_juego::sendMensaje(string msj){
//aqui se va a enviar hacia el servidor
    qDebug()<<"Enviando desde crear juego";
    conexion2->setMensaje(msj.c_str());


}



void crear_juego::on_botonCrear_clicked(){
    //aqui se validan los datos ingresados y se le mandan al servidor
    QString nombreIngresado = ui->nombre->text();
    int jugadores = ui->cantidadJugadores->value();


    if(estaConectado == true){
        sendMensaje(converter->convertirInicial(nombreIngresado,jugadores));
        //ui->nombre->clear();
        ui->cantidadJugadores->clear();
        qDebug() << "Mensaje enviado";

    }
    else{
       qDebug() << "No se pudo enviar el mensaje ya que no me he conectado al servidor";
       ui->nombre->clear();
       ui->cantidadJugadores->clear();
    }











}


