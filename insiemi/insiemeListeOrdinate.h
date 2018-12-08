//
// Created by arcangelo on 05/11/18.
//

#ifndef TEST_BUILD_INSIEMELISTEORDINATE_H
#define TEST_BUILD_INSIEMELISTEORDINATE_H

#include "insiemi.h"
#include "../listaTemplate/listaPointerSort.h"

template <class T>
class insiemeList;

template <class T>
class cella {
public:
    friend class insiemeList<T>;
    cella<T> operator<(const cella<T>& c ) const { return this->value < c.value; };
    cella<T> operator<=(const cella<T>& c) const { return this->value <= c.value; };
    cella<T> operator>(const cella<T>& c) const { return this->value > c.value; };
private:
    T value;
    cella<T> * prev;
    cella<T> * succ;
};

template <class T>
class insiemeList : public insieme<T,cella<T>*>{
private:
    typedef typename listalineare<T, cella<T>*>::value_type value_type;
    listPointer<T> insieme;
    int lenght;
public:
    insiemeList(){
        crea();
    };
    ~insiemeList(){
        delete insieme;
    };
    void crea(){
        if(insiemeVuoto()){
            lenght = 0;
        }
    };
    bool insiemeVuoto(){
        return insieme.listaVuota();
    }
    bool appartiene(value_type &a){
        listPointer<int>::position iter;
        iter = 0;
        while(!insieme.fineLista(iter)){
            if(a == insieme.leggiLista(iter)){
                return true;
            }
            iter ++;
        }
        return false;
    }


    void inserisci(value_type &a){
        if(!appartiene(a)){
            insieme.insLista(a,insieme.primoLista());
        }
    }

    void cancella(value_type &a){
        if(appartiene(a)){
            insieme.cancLista(insieme.leggiLista(a));
        }
    }

    void unione(insieme i){
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

    void intersezione(insieme i){
        insieme intersection;
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

    void differenza(insieme i){
        insieme diff;
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
