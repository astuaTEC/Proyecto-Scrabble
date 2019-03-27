//
// Created by saymon on 25/03/19.
//

#ifndef PROYECTO_CONVERTER_H
#define PROYECTO_CONVERTER_H

#include <document.h>
#include <Dealer/Ficha.h>
#include <Estructuras/List.h>

using namespace rapidjson;
using namespace std;

class Converter {


private:
    static Converter* instance;

    Converter();

public:

    void JsonToFicha(const char*);
    static Converter* getInstance();
    const char* FichasToJson(List<Ficha>*);


};


#endif //PROYECTO_CONVERTER_H
