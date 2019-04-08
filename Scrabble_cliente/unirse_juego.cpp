#include "unirse_juego.h"
#include "ui_unirse_juego.h"
#include "inicio_ventana.h"
#include "juego.h"
#include "socketcliente.h"
#include <QDebug>

extern Juego *juego;
//Juego *juego;
unirse_juego::unirse_juego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::unirse_juego)
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

    QPalette pal2 = ui->botonUnirse_2->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::yellow));
      ui->botonUnirse_2->setAutoFillBackground(true);
      ui->botonUnirse_2->setPalette(pal2);
      ui->botonUnirse_2->update();

      //cambiale el color a los textos
      QPalette palette = ui->contraLabel->palette();
      palette.setColor(ui->contraLabel->backgroundRole(), Qt::yellow);
      palette.setColor(ui->contraLabel->foregroundRole(), Qt::yellow);
      ui->contraLabel->setPalette(palette);

      QPalette palette2 = ui->contraLabel_2->palette();
      palette2.setColor(ui->contraLabel_2->backgroundRole(), Qt::yellow);
      palette2.setColor(ui->contraLabel_2->foregroundRole(), Qt::yellow);

      //inicializamos las variables publicas
      estaConectado = false;
      ui->contraLabel_2->setPalette(palette2);

      //crear un objeto converter
      converter = Converter::getInstance();

      //CONFIGURACION DEL SOCKET
      conexion = new SocketCliente;

      //iniciarl el socket
      iniciarConexion();




      cont = 0;





}

unirse_juego::~unirse_juego()
{
    delete ui;
}

void unirse_juego::iniciarConexion(){
    if(conexion->connectar()){
        connect(conexion,SIGNAL(NewMensaje(QString)),SLOT(RecibirMensaje(QString)));
        estaConectado = true;
        qDebug() << "Estamos conectados al servidor";
    }

    else{
        qDebug() << "Error al conectarse con el servidor";
    }

}

void unirse_juego::iniciarJuego(){
    juego->show();

    juego->GenerarListaConexion(json,conexion,ui->nombreLineEdit->text(),false);

    juego->Iniciar();
    //juego->recibirNombres(converter->nombres);


    close();

}



void unirse_juego::on_botonVolver_clicked(){
    //volver a la ventana inicial
    inicio_ventana *ventanaInicial = new inicio_ventana();
    ventanaInicial->show();
    //cerramos la ventana
    close();


}

void unirse_juego::RecibirMensaje(QString mensaje){

   qDebug() <<"mensaje en unirse juego"<< mensaje;


    if(!converter->fichasRecibidas && converter->aceptado){
        qDebug()<<"entrando a fichasRecibidas unirse";
        //ahora se inicia el juego
        json = mensaje;
        iniciarJuego();

        converter->fichasRecibidas = true;


    }


    if(!converter->aceptado){
       qDebug() <<"entrando a aceptado en unirse";
        converter->funcionGeneral(QString(mensaje).toStdString().c_str());
    }


}

void unirse_juego::sendMensaje(string msj){
    conexion->setMensaje(msj.c_str());

}

void unirse_juego::on_botonUnirse_2_clicked(){
    //aqui se validan los datos ingresados y se le mandan al servidor
    QString contraIngresada = ui->contraLineEdit->text();
    QString nombreIngresado = ui->nombreLineEdit->text();

    if(estaConectado == true){
        sendMensaje(converter->unirse(contraIngresada.toInt(),nombreIngresado.toStdString()));
        ui->contraLineEdit->clear();
        //ui->nombreLineEdit->clear();
        qDebug() << "Mensaje enviado";

    }
    else{
       qDebug() << "No se pudo enviar el mensaje ya que no me he conectado al servidor";
    }









}


