//
// Created by arcangelo on 05/11/18.
//

#ifndef TEST_BUILD_INSIEMELISTEORDINATE_H
#define TEST_BUILD_INSIEMELISTEORDINATE_H

#include "insiemi.h"
#include "../listaTemplate/listaPointerSort.h"


template <class T>
class insiemeList : public insieme<T,cella<T>*>{
private:
    typedef typename listalineare<T, cella<T>*>::value_type value_type;
    typedef typename listalineare<T, cella<T>*>::position position;
    listPointer<T> insiemeElem;
    int lenght;
public:
    insiemeList(){
        crea();
    };
    ~insiemeList(){
        delete insiemeElem;
    };
    void crea(){
        if(vuoto()){
            lenght = 0;
        }
    };
    bool vuoto(){
        return insiemeElem.listaVuota();
    }
    bool appartiene(value_type &a) const{
        listPointer<int>::position iter;
        iter = 0;
        while(!insiemeElem.fineLista(iter)){
            if(a == insiemeElem.leggiLista(iter)){
                return true;
            }
            iter ++;
        }
        return false;
    }


    void inserisci(value_type &a){
        if(!appartiene(a)){
            insiemeElem.insLista(a,insiemeElem.primoLista());
        }
    }

    void cancella(value_type &a){
        if(appartiene(a)){
            insiemeElem.cancLista(insiemeElem.leggiLista(a));
        }
    }

    void unione(insiemeList<T> i){
        position iter = i.primoLista();
        value_type v ;
        while (!i.fineLista(iter)){
            v = i.legglista(iter);
            if(!appartiene(v)){
                inserisci(v);
            }
            iter = succLista(iter);
        }
    }

    void intersezione(insiemeList<T> i){
        insiemeList<T> intersection;
        position iter = i.primoLista();
        value_type v ;
        while (!i.fineLista(iter)){
            v = i.legglista(iter);
            if(appartiene(v)){
                intersection.inserisci(v);
            }
            iter = succLista(iter);
        }
        this = intersection;
    }

    void differenza(insiemeList<T> i){
        insiemeList<T> diff;
        position iter = i.primoLista();
        value_type v ;
        while (!i.fineLista(iter)){
            v = i.legglista(iter);
            if(!appartiene(v)){
                diff.inserisci(v);
            }
            iter = succLista(iter);
        }
        this = diff;
    }




};

#endif //TEST_BUILD_INSIEMELISTEORDINATE_H
