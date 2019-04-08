#ifndef CONVERTER_H
#define CONVERTER_H


#include <include/rapidjson/document.h>
#include "Ficha.h"


using namespace rapidjson;
using namespace std;

class Converter {


private:
    /**
     * @brief instance Instancia de converter.
     */
    static Converter* instance;
    /**
     * @brief Converter Metodo constructor.
     */
    Converter();

public:

    int claveGenerada;
    //booleano para saber si ya puedo abrir el juego o no
    bool aceptado;
    bool fichasRecibidas;
    /**
     * @brief repartaCartas Dice cuando repartir las fichas.
     * @return Un json con las fichas
     */
    string repartaCartas();
    /**
     * @brief JsonToFicha Convertir un json a ficha.
     * @return Fichas
     */
    QList<Ficha*> JsonToFicha(const char*);
    /**
     * @brief getInstance Obtiene la instancia de la clase.
     * @return La instancia.
     */
    static Converter* getInstance();
    /**
     * @brief PalabraToJson Convierte una palabra a json.
     * @param fichasJugadas Las fichas que se han puesto en el tablero.
     * @return  Un json.
     */
    string PalabraToJson(QList<Ficha*> fichasJugadas);

    void mostrarClave(const char*);
    /**
     * @brief funcionGeneral Un receptor de solicitudes variadas.
     */
    void funcionGeneral(const char*);
    /**
     * @brief pasarFicha Agrega las fichas a una lista.
     */
    void pasarFicha(const char*);

    void validarPalabra(const char*);
    void verificarClave(int);
    void generarClave(int);
    /**
     * @brief jsonToPalabra Convierte un json a una palabra.
     * @param json El json.
     * @return Una palabra.
     */
    QList<Ficha*> jsonToPalabra(const char* json);
    /**
     * @brief pasarLetra Agrega las letras.
     * @param letras Las letras.
     */
    void pasarLetra(const char* letras);
    /**
     * @brief inicializarPuntajes Poner los puntajes iniciales.
     * @param json El json.
     */
    void inicializarPuntajes(const char* json);
    /**
     * @brief pasarNombres Agrega los nombres.
     * @param n Un string.
     */
    void pasarNombres(const char* n);
    /**
     * @brief convertirInicial valida una contraseña inicial.
     * @param nombre Nombre del jugador.
     * @param jugadores La cantidad de jugadores.
     * @return Un json.
     */
    string convertirInicial(QString nombre, int jugadores);
    string unirse(int clave, string nombre);

    int confirmarPalabra(const char* resultado);

    QList<Ficha*> fichas;
    //fichas que se van a actualizar
    QList<Ficha*> fichasActualizacion;

    //lista de nombres
    QList<QString> nombres;
    QList<int> puntajes;
    QString turnoDe;



    bool llegaResultado;
    bool llegaPalabra;
    bool llegaPuntajes;
    bool llegaTurno;

};

#endif // CONVERTER_H
