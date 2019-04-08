//
// Created by saymon on 17/03/19.
//
//https://ronnyml.wordpress.com/2009/07/04/listas-enlazadas-clase-lista-en-c/


#ifndef PROYECTO_LISTA_H
#define PROYECTO_LISTA_H

#include <string>
#include "Node.h"
#include "Node.cpp"

using namespace std;

template <class T>

class List{

public:
    List();
    ~List();

    void add_head(T);
    void del_by_data(T);
    T indice(int);
    int getTam();
    void print();
    void del_all();
    void del_by_position(int);


private:
    Node<T> *m_head;
    int m_num_nodes;
};

#endif //PROYECTO_LISTA_H
