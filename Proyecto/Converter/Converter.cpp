//
// Created by saymon on 25/03/19.
//

#include "Converter.h"
#include <document.h>
#include <Tablero/Tablero.h>
#include <vector>
#include <include/rapidjson/fwd.h>
#include <include/rapidjson/stringbuffer.h>
#include <writer.h>

using namespace std;
using namespace rapidjson;

Converter* Converter::instance = 0;

Converter* Converter::getInstance()
{
    if (instance == 0)
    {
        instance = new Converter();
    }

    return instance;
}

Converter::Converter() {

}

void Converter::JsonToFicha(const char* json) {

    auto tablero = Tablero::getInstance();

    Document document;
    document.Parse(json);
    assert(document.IsObject());

    assert(document.HasMember("fila"));
    assert(document["fila"].IsInt());
    assert(document.HasMember("columna"));
    assert(document["colunma"].IsInt());
    assert(document.HasMember("letra"));
    assert(document["letra"].IsString());
    assert(document.HasMember("valor"));
    assert(document["valor"].IsInt());



    tablero->agregar(document["fila"].GetInt(), document["columna"].GetInt(), document["letra"].GetString(),document["valor"].GetInt());


}

const char* Converter:: FichasToJson(List<Ficha> *pList){
    StringBuffer a;
    Writer<StringBuffer> writer2(a);

    writer2.StartObject();
    writer2.Key("fichas");
    writer2.StartArray();

    for(int i=0; i < pList->getTam(); i++) {
        Ficha ficha= pList->indice(i);
        StringBuffer s;
        vector<string> vec;
        Writer<StringBuffer> writer(s);
        writer.StartObject();
        writer.Key("letra");
        writer.String(ficha.getLetra().c_str());
        writer.Key("valor");
        writer.Uint(static_cast<unsigned int>(ficha.getValor()));
        writer.EndObject();
        writer2.String(s.GetString());

    }
   // pList->del_all();
    writer2.EndArray();
    writer2.EndObject();

    cout<< a.GetString()<< endl;
    return a.GetString();

}