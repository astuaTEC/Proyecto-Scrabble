#include "inicio_ventana.h"
#include "ui_inicio_ventana.h"
#include "crear_juego.h"
#include "unirse_juego.h"

inicio_ventana::inicio_ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inicio_ventana)
{
    ui->setupUi(this);

    QPixmap pix("/home/kevin/Descargas/fondo_opt.jpg");
    ui->imagen->setPixmap(pix);

    //cambiarle el color a los botones
    QPalette pal = ui->crearJuego->palette();
    pal.setColor(QPalette::Button, QColor(Qt::darkRed));
     ui->crearJuego->setAutoFillBackground(true);
     ui->crearJuego->setPalette(pal);
     ui->crearJuego->update();

    QPalette pal2 = ui->unirseJuego->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::darkRed));
      ui->unirseJuego->setAutoFillBackground(true);
      ui->unirseJuego->setPalette(pal2);
      ui->unirseJuego->update();

      QPalette pal3 = ui->salir->palette();
      pal3.setColor(QPalette::Button, QColor(Qt::darkRed));
         ui->salir->setAutoFillBackground(true);
         ui->salir->setPalette(pal3);
         ui->salir->update();

      //cambiale el color a los textos
      QPalette palette = ui->label->palette();
      palette.setColor(ui->label->backgroundRole(), Qt::yellow);
      palette.setColor(ui->label->foregroundRole(), Qt::yellow);
      ui->label->setPalette(palette);



}

inicio_ventana::~inicio_ventana()
{
    delete ui;
}



void inicio_ventana::on_crearJuego_clicked(){
    //por medio de este metodo se direcciona a la ventana de "crear_juego"
    crear_juego *ventana_crearJuego = new crear_juego();
    ventana_crearJuego->show();

    //cerramos esta ventana
    close();

}

void inicio_ventana::on_unirseJuego_clicked(){
    //por medio de este metodo se direcciona a la ventana de "unirse_juego"
    unirse_juego *unirseJuego = new unirse_juego();
    unirseJuego->show();

    //cerramos la ventana actual
    close();
}

void inicio_ventana::on_salir_clicked(){
    close();
}
