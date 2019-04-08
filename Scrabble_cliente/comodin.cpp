#include "comodin.h"
#include <QBrush>
#include <juego.h>
#include <QPolygonF>
#include <QVector>
#include <QDebug>
#include <QGraphicsTextItem>
extern Juego* juego;
Comodin::Comodin(QGraphicsItem *parent){
   QVector<QPointF> puntosComodin;
   puntosComodin << QPointF(0,0) << QPointF(1,0) << QPointF(1,1) << QPointF(0,1);

   //escala de los puntos
   int escala = 45;
   for(size_t i =0, n = puntosComodin.size(); i < n ; i++){
       puntosComodin[i] *= escala;
   }
   //crear un cuadrado
   QPolygonF cuadradito(puntosComodin); //se le pasan los puntos

   //dibujar el  poligono
   setPolygon(cuadradito);

   //ponerle color a los comodines
   QBrush brush;
   brush.setStyle(Qt::SolidPattern);
   brush.setColor(Qt::gray);
   setBrush(brush);

   //crear los textos
   letraTexto = new QGraphicsTextItem(letra,this);
   letraTexto->setScale(1);
   letraTexto->setPos(10,6);



}

void Comodin::setLetra(QString l){
    letra = l;

}

QString Comodin::getLetra(){
    return letra;

}

void Comodin::setTexto(QString l){
    setLetra(l);
    letraTexto->setPlainText(letra);

}



void Comodin::mousePressEvent(QGraphicsSceneMouseEvent *event){
   //primero extraigo la letra que se ha seleccionado
    qDebug() << "La letra comodin es : "+ getLetra();
   //quitar todos los elementos de la pantalla de comodines
    juego->quitarComodines();
    //le paso la nueva letra
    juego->cartaParaPoner->setTexto(getLetra());

    //desbloqueo
    juego->setBloqueo(false);

}
