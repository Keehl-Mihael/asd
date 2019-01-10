//
// Created by siroid on 1/9/19.
//

#ifndef TEST_BUILD_GRAFOLIST2_H
#define TEST_BUILD_GRAFOLIST2_H

#include "Grafo.h"
#include <list>
#include <map>


class Nodo;

template <class P>
class Arco{
    Nodo dest;
    P peso;
};


class Nodo{
private:
    int id;
public:
    Nodo(){};
    Nodo(int val){ id = val;}
    void setId(int val){ id = val;}
    int getId(){return id;}

};

template <class E>
class infoNodo{
    E etichetta;
    std::list<Nodo> adj;
};



template <class C,class D>
class GrafoList2 : public Grafo<C,D,Nodo>{

};

#endif //TEST_BUILD_GRAFOLIST2_H
