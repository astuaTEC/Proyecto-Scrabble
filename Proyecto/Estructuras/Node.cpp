//
// Created by saymon on 17/03/19.
//
//https://ronnyml.wordpress.com/2009/07/04/listas-enlazadas-clase-lista-en-c/


#include <clocale>
#include <iostream>
#include "Node.h"


// Constructor por defecto
template<typename T>

Node<T>::Node()
{
    data = NULL;
    next = NULL;
}

// Constructor por parámetro
template<typename T>
Node<T>::Node(T data_)
{
    data = data_;
    next = NULL;
}

// Eliminar todos los Nodos
template<typename T>
void Node<T>::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}


template<typename T>
Node<T>::~Node() {}

template<class T>
T Node<T>::getData() {
    return this->data;
}

template<typename T>
void Node<T>::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << &data << "-> ";
}