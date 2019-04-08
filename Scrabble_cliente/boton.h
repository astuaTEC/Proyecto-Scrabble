#ifndef BOTON_H
#define BOTON_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
/**
 * @brief The Boton class
 * Esta clase se encarga de proporcionar botones a la interfaz grafica.
 */
class Boton:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    /**
     * @brief Boton  Constructor de la clase Boton.
     * @param nombre Nombre del boton.
     * @param parent Ventana.
     */
    Boton(QString nombre, QGraphicsItem* parent = NULL);

    /**
     * @brief mousePressEvent Evalua cuando se presiona el boton.
     * @param evento Evento
     *
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* evento);
    /**
     * @brief hoverEnterEvent Evalua cuando pasa por el boton.
     * @param evento Evento
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent* evento);
    /**
     * @brief hoverLeaveEvent Evalua cuando sale del boton.
     * @param evento
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* evento);

signals:
    /**
     * @brief clicked Cuando le damos click al boton
     */
    void clicked();


private:
    /**
     * @brief texto Texto que aparece en el boton.
     */
    QGraphicsTextItem *texto;

};

#endif // BOTON_H
