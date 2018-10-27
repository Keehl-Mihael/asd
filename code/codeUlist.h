//
// Created by arcangelo on 10/27/18.
// code che utilizzano le liste con singolo puntaotre con flag
//

#ifndef PROJECT_CODEULIST_H
#define PROJECT_CODEULIST_H

#include "listaSinglePointerFlag.h"

template <class T>
class codaList {
private :
    listasinglepointerflag<T> coda;
public:

    typedef typename listalineare<T, cella<T>*>::value_type value_type;

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
        return 
    }



};

#endif //PROJECT_CODEULIST_H
