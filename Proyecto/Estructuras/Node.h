//
// Created by saymon on 17/03/19.
//
//https://ronnyml.wordpress.com/2009/07/04/listas-enlazadas-clase-lista-en-c/


#ifndef PROYECTO_NODE_H
#define PROYECTO_NODE_H

using namespace std;

template <class T>

class Node
{
public:
    Node();
    Node(T);
    ~Node();

    Node *next;
    T data;

    void delete_all();
    T getData();
    void print();


};
#endif //PROYECTO_NODE_H
