#include "ventana_inicial.h"
#include "ui_ventana_inicio.h"
#include "crear_juego.h"
#include "unirse_juego.h"

ventana_inicial::ventana_inicial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventana_inicio)
{
    ui->setupUi(this);

    QPixmap pix("/home/kevin/Descargas/image1_opt.jpg");
    ui->imagen->setPixmap(pix);


    //cambiarle el color a los botones
    QPalette pal = ui->unirseJuego->palette();
    pal.setColor(QPalette::Button, QColor(Qt::darkRed));
    ui->unirseJuego->setAutoFillBackground(true);
    ui->unirseJuego->setPalette(pal);
    ui->unirseJuego->update();

    QPalette pal2 = ui->crearJuego->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::darkRed));
    ui->crearJuego->setAutoFillBackground(true);
    ui->crearJuego->setPalette(pal2);
    ui->crearJuego->update();

    QPalette pal3 = ui->salir->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::darkRed));
    ui->salir->setAutoFillBackground(true);
    ui->salir->setPalette(pal3);
    ui->salir->update();

    //cambiale el color a los textos
    QPalette palette = ui->label_2->palette();
    palette.setColor(ui->label_2->backgroundRole(), Qt::yellow);
    palette.setColor(ui->label_2->foregroundRole(), Qt::yellow);
    ui->label_2->setPalette(palette);



}

ventana_inicial::~ventana_inicial()
{
    delete ui;
}

void ventana_inicial::on_salir_clicked(){
    //slot para cerrar la ventana
    close();

}

void ventana_inicial::on_crearJuego_clicked(){
    //por medio de este metodo se direcciona a la ventana de "crear_juego"
    crear_juego *ventana_crearJuego = new crear_juego();
    ventana_crearJuego->show();

    //cerramos esta ventana
    close();

}

void ventana_inicial::on_unirseJuego_clicked(){
    //por medio de este metodo se direcciona a la ventana de "unirse_juego"
    unirse_juego *unirseJuego = new unirse_juego();
    unirseJuego->show();

    //cerramos la ventana actual
    close();


}




