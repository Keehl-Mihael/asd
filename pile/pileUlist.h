//
// Created by arcangelo on 10/27/18.
// pile che utilizzano le liste con singolo puntatore
//

#ifndef PROJECT_PILEULIST_H
#define PROJECT_PILEULIST_H

#include "listaSinglePointer.h"

template <class T>
class pileList {
private :
    listasinglepointerflag<T> pila;
public:

    typedef typename listalineare<T, cella<T>*>::value_type value_type;
    typedef typename listalineare<T, cella<T>*>::position position;

    void creapila(){
        pila.crealista();
    }
    bool pilavuota(){
        return pila.listavuota();
    }
    value_type leggipila(){
        return pila.leggilista(pila.primolista());
    }
    void fuoripila(){
        return pila.canclista(pila.primolista());
    }

    void inpila(value_type v){
        pila.inslista(v,pila.primolista());
    }



};

#endif //PROJECT_CODEULIST_H
