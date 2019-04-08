#ifndef TABLERO_H
#define TABLERO_H
#include <QList>
#include "Ficha.h"
#include "comodin.h"

/**
 * @brief The Tablero class Constrola el tablero que se muestra en el juego.
 */
class Tablero
{
public:
    /**
     * @brief Tablero Constructor.
     */
    Tablero();

    //getters and setters
    QList<Ficha*> getFichas();

    /**
     * @brief ponerFichas Pone las fichas en la pantalla.
     * @param x X
     * @param y Y
     * @param columnas Columnas
     * @param filas Filas
     */
    void ponerFichas(int x,int y,int columnas,int filas);
    /**
     * @brief ponerComodines Poner los comodines cuando se piden.
     * @param x
     * @param y
     * @param columnas
     * @param filas
     */
    void ponerComodines(int x,int y,int columnas,int filas);
    /**
     * @brief ponerLetrasComodines Asigna las letras en los comodines.
     * @param misComodines Una lista.
     */
    void ponerLetrasComodines(QList<Comodin*> misComodines);
    //metodo para inicializar los valores de la matriz
    void valoresMatrix();
    /**
     * @brief crearColumnaFichas Crea las columnas del tablero.
     * @param x X
     * @param y Y
     * @param numFilas Filas
     */
    void crearColumnaFichas(int x,int y,int numFilas);
    /**
     * @brief crearColumnaComodines Crea las columnas de los comodines.
     * @param x X
     * @param y Y
     * @param numFilas Filas
     */
    void crearColumnaComodines(int x,int y,int numFilas);
    QList<Ficha*> fichas;
    QList<Comodin*> comodines;





    //lista de las letras del abecedario para los comodines
    QList<QString> letrasComodines;
};
#endif // TABLERO_H
