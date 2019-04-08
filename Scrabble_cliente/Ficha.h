#ifndef FICHA_H
#define FICHA_H
#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QPointF>
/**
 * @brief The Ficha class Permiite crear y graficar las fichas en el juego.
 */
class Ficha: public QGraphicsPolygonItem{
public:
    /**
     * @brief Ficha Constructor .
     * @param parent
     */
    Ficha(QGraphicsItem* parent =NULL);

    /**
     * @brief mousePressEvent Cuando se presiona una ficha.
     * @param event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    /**
     * @brief getEstaPuesta Validar si la ficha esta puesta.
     * @return Un bool.
     */
    bool getEstaPuesta();
    /**
     * @brief getDueno Da el dueño de la ficha.
     * @return dueño.
     */
    QString getDueno();
    /**
     * @brief getLetra Da la letra correspondiente.
     * @return La letra.
     */
    QString getLetra();
    /**
     * @brief getFila Da la fila en la que se encuentra.
     * @return La fila.
     */
    int getFila();
    /**
     * @brief getColumna Da la columna en la que se encuentra.
     * @return La columna.
     */
    int getColumna();


    void setDueno(QString Dueno);
    /**
     * @brief setEstaPuesta Modificar el esta puesta.
     * @param Estapuesta El nuevo valor.
     */
    void setEstaPuesta(bool Estapuesta);
    /**
     * @brief setTexto Modifica el texto que se muestra graficamente.
     * @param l El nuevo texto.
     */
    void setTexto(QString l);
    /**
     * @brief setTextoValor Modifica el valor equivalente de la ficha.
     * @param Valor El nuevo valor.
     */
    void setTextoValor(int Valor);
    /**
     * @brief setValor Modifica el valor.
     * @param Valor El valor.
     */
    void setValor(int Valor);
    /**
     * @brief getValor Obtener el valor.
     * @return El valor.
     */
    int getValor();
    /**
     * @brief setLetra Modificar la letra.
     * @param Letra La nueva letra.
     */
    void setLetra(QString Letra);
    /**
     * @brief letrasVisibles Hace que se muestren la letras.
     */
    void letrasVisibles();
    /**
     * @brief setEsComodin Modificar si es un comodin.
     * @param Un bool.
     */
    void setEsComodin(bool es);
    /**
     * @brief getEsComodin Dice si la ficha es un comodin.
     * @return Un bool
     */
    bool getEsComodin();
    /**
     * @brief setColumna Modificar el valor de la columna.
     * @param c El nuevo valor.
     */
    void setColumna(int c);
    /**
     * @brief setFila Modifica el valor de la fila.
     * @param f El nuevo valor.
     */
    void setFila(int f);

    //atributos publicos
    QPointF posicionOriginal;

    bool intocable;



private:
    //posiciones en la matriz
    int columna;
    int fila;

    int valor;

    //otros atributos
    bool estaPuesta;
    bool esComodin;
    QString dueno;
    QString letra;
    QGraphicsTextItem* letraTexto;
    QGraphicsTextItem* valorTexto;


};

#endif // FICHA_H
