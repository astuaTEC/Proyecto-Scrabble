//
// Created by saymon on 25/03/19.
//

#ifndef PROYECTO_CONVERTER_H
#define PROYECTO_CONVERTER_H

#include <include/rapidjson/document.h>
#include <Dealer/Ficha.h>
#include <Estructuras/List.h>
#include <QList>
#include <socketserver.h>
#include <Tablero/Tablero.h>

using namespace rapidjson;
using namespace std;

class Converter {


private:

    static Converter* instance;
    Converter();

public:

    void JsonToFicha(const char*, int);
    int mandarArecorrer(const char* json);
    static Converter* getInstance();
    const char * FichasToJson(QList<Ficha*>);
    void funcionGeneral(const char*, int);
    void pasarFicha(const char*);
    void validarPalabra(const char*);
    void verificarClave(int, int, string);
    void generarClave(const char *clave);
    void verificarCompartir();
    void enviar();

    int fila;
    int columna;

};


#endif //PROYECTO_CONVERTER_H
