#ifndef COMODIN_H
#define COMODIN_H
#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
/**
 * @brief The Comodin class Proporciona una pequeña interfaz para mostrar los comodines.
 */
class Comodin: public QGraphicsPolygonItem{
public:
    /**
     * @brief Comodin Constructor.
     * @param parent
     */
    Comodin(QGraphicsItem* parent =NULL);
    /**
     * @brief setLetra Modificar la letra.
     * @param l La letra.
     */
    void setLetra(QString l);
    /**
     * @brief getLetra Obtener la letra.
     * @return La letra.
     */
    QString getLetra();
    /**
     * @brief setTexto Modificar el texto que se muestra.
     * @param l
     */
    void setTexto(QString l);

    /**
     * @brief mousePressEvent Cuando presionamos una ficha comodin.
     * @param event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event);




private:
    /**
     * @brief letra La letra.
     */
    QString letra;
    /**
     * @brief letraTexto El texto.
     */
    QGraphicsTextItem* letraTexto;
};


#endif // COMODIN_H
