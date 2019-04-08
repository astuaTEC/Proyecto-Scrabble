#include "boton.h"
#include <QGraphicsTextItem>
#include <QBrush>
Boton::Boton(QString nombre , QGraphicsItem *parent): QGraphicsRectItem (parent){
    //dibujar el rectangulo
    setRect(0,0,100,70);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    //dibujar el texto
    texto = new QGraphicsTextItem(nombre,this);
    int xPos = rect().width()/2 - texto->boundingRect().width()/2;
    int yPos = rect().height()/2 - texto->boundingRect().height()/2;

    texto->setPos(xPos,yPos);

    //permitir la respuesta a hover events
    setAcceptHoverEvents(true);

}

void Boton::mousePressEvent(QGraphicsSceneMouseEvent *evento){
    emit clicked();
}

void Boton::hoverEnterEvent(QGraphicsSceneHoverEvent *evento){
    //cambiar el color
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);


}

void Boton::hoverLeaveEvent(QGraphicsSceneHoverEvent *evento){
    //cambiar el color
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

}
