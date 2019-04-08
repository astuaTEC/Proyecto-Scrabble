#include "Ficha.h"
#include <QBrush>
#include <juego.h>
#include <QPolygonF>
#include <QVector>
#include <QDebug>
#include <QGraphicsTextItem>

extern Juego* juego;
Ficha::Ficha(QGraphicsItem *parent){
    //se dibuja un cuadrado
    QVector<QPointF> puntosFicha;
    puntosFicha << QPointF(0,0) << QPointF(1,0) << QPointF(1,1) << QPointF(0,1);

    //escala de los puntos
    int escala = 40;
    for (size_t i = 0, n = puntosFicha.size();i < n; i++){
        puntosFicha[i] *= escala;

    }
    //crear un poligono con la escala de las fichas
    QPolygonF cuadrado(puntosFicha);

    //dibujar el poligono
    setPolygon(cuadrado);

    //inicializar
    estaPuesta = false;

    //crear los textos de la letra
    letraTexto = new QGraphicsTextItem(letra,this);
    letraTexto->setScale(1.3);
    letraTexto->setPos(4,3);


    //crear el texto del valor
    valorTexto = new QGraphicsTextItem("3",this);
    valorTexto->setScale(0.8);
    valorTexto->setPos(23,23);

    //hacer la letra y el valor invisibles
    letraTexto->setVisible(false);
    valorTexto->setVisible(false);

    intocable = false;




}

void Ficha::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //si la ficha no esta puesta y no esta bloqueada la pantalla, es una carta, entonces levantela
    qDebug()<<"bool"<<juego->bloqueoturno;
    if (getEstaPuesta() == false && juego->getBloqueo() == false ){

        //si la ficha seleccionada es un comodin
        if(getEsComodin() == true){
            juego->dibujarPanelComodin();
            //bloqueo
            juego->setBloqueo(true);
        }

        juego->levantarCarta(this);

    }
    //si la ficha está en el tablero, no hay bloqueo y hay una carta levantada
    if (getEstaPuesta() == true && juego->getBloqueo() == false && juego->cartaParaPoner != NULL ){

        juego->ponerCarta(this);







    }


        }

bool Ficha::getEstaPuesta(){
     return estaPuesta;
    }

QString Ficha::getDueno(){
    return dueno;

}

QString Ficha::getLetra(){
    return letra;

}

int Ficha::getFila(){
    return fila;

}

int Ficha::getColumna(){
    return columna;

}

void Ficha::setDueno(QString Dueno){
    //set el dueno
    dueno = Dueno;

    //cambiar el color
    if (Dueno == QString("NADIE")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::lightGray);
        setBrush(brush);
    }
    if (Dueno == QString("JUGADOR")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::yellow);
        setBrush(brush);
    }


}

void Ficha::setEstaPuesta(bool Estapuesta){
    estaPuesta = Estapuesta;

}

void Ficha::setTexto(QString l){
    setLetra(l);
    letraTexto->setPlainText(letra);
}

void Ficha::setTextoValor(int Valor){
    setValor(Valor);
valorTexto->setPlainText(QString::number(valor));

}

void Ficha::setValor(int V){
    valor = V;



}

int Ficha::getValor(){
    return valor;

}

void Ficha::setLetra(QString Letra){
    letra = Letra;

}

void Ficha::letrasVisibles(){
   letraTexto->setVisible(true);
   valorTexto->setVisible(true);

}

void Ficha::setEsComodin(bool es){
    esComodin = es;

}

bool Ficha::getEsComodin(){
    return esComodin;

}

void Ficha::setColumna(int c){
    columna = c;

}

void Ficha::setFila(int f){
    fila = f;

}
