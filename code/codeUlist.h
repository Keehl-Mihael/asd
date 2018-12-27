//
// Created by arcangelo on 10/27/18.
// code che utilizzano le liste con singolo puntatore
//

#ifndef PROJECT_CODEULIST_H
#define PROJECT_CODEULIST_H

#include "../liste/listaSinglePointer.h"

template <class T>
class codaList {
private :
    listasinglepointer<T> coda;
public:

    typedef typename listalineare<T, cella<T>*>::value_type value_type;
    typedef typename listalineare<T, cella<T>*>::position position;

    void creacoda(){
        coda.creaLista();
    }

    bool codavuota(){
        return coda.listaVuota();
    }
    value_type leggicoda(){
        return coda.leggiLista(coda.primoLista());
    }
    void fuoricoda(){
        return coda.leggiLista(coda.primoLista());
    }

    void incoda(value_type v){
        position start = coda.primoLista();
        while(fineLista(start) != true){
            start = coda.succLista(start);
        }
        coda.insLista(v,start);
    }



};

#endif //PROJECT_CODEULIST_H
