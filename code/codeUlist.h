//
// Created by arcangelo on 10/27/18.
// code che utilizzano le liste con singolo puntatore
//

#ifndef PROJECT_CODEULIST_H
#define PROJECT_CODEULIST_H

#include "listaSinglePointer.h"

template <class T>
class codaList {
private :
    listasinglepointerflag<T> coda;
public:

    typedef typename listalineare<T, cella<T>*>::value_type value_type;
    typedef typename listalineare<T, cella<T>*>::position position;

    void creacoda(){
        coda.crealista();
    }
    bool codavuota(){
        return coda.listavuota();
    }
    value_type leggicoda(){
        return coda.leggilista(coda.primolista());
    }
    void fuoricoda(){
        return coda.canclista(coda.primolista());
    }

    void incoda(value_type v){
        position start = coda.primolista();
        while(finelista(start) != true){
            start = coda.succlista(start);
        }
        coda.inslista(v,start);
    }



};

#endif //PROJECT_CODEULIST_H
