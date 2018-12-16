//
// Created by arcangelo on 10/18/18.
//

#ifndef ASD_LISTASINGLEPOINTER_H
#define ASD_LISTASINGLEPOINTER_H

#include "lista.h"



template <class T>
class listasinglepointer ;


template <class T>
class cella {
public:
    friend class listasinglepointer<T>;

    cella<T> operator<(const cella<T>& c ) const { return this->value < c.value; };
    cella<T> operator<=(const cella<T>& c) const { return this->value <= c.value; };
    cella<T> operator>(const cella<T>& c) const { return this->value > c.value; };
private:
    T value;
    cella<T> * succ;
};


template <class T>
class listasinglepointer: public listalineare <T,cella<T>*> {


private:
    cella<T>* head;
    int lenght;
public:

    typedef typename listalineare<T, cella<T>*>::value_type value_type;
    typedef typename listalineare<T, cella<T>*>::position position;

    listasinglepointer();
    ~listasinglepointer();
    void creaLista();
    bool listaVuota() const;
    value_type leggiLista(position) const;
    void scriviLista(const value_type &a,position);
    position primoLista() const;
    bool fineLista(position) const;
    position succLista(position) const;
    position predLista(position) const;
    void insLista(value_type,position);
    void cancLista(position);
    int lunghezza() const ;
    void inverti() ;
    bool palindroma() ;

    // sovraccarico di operatori
    listasinglepointer<T>& operator=(const listasinglepointer<T>&); // the assignment operator
    bool operator==(const listasinglepointer<T> &) const; // tests two list for equality

};



template <class T>
listasinglepointer<T>::listasinglepointer(){
    head = new cella<T>;
    head-> succ = head;
    lenght = 0;
}

template <class T>
listasinglepointer<T>::~listasinglepointer(){
    delete[] head;
}

template <class T>
void listasinglepointer<T>::creaLista() {
    if(listaVuota()){
        lenght = 0;
    }
}
template <class T>
int listasinglepointer<T>::lunghezza() const{
    return (lenght);
}

template <class T>
bool listasinglepointer<T>::palindroma(){
    return false;
}

template <class T>
void listasinglepointer<T>::inverti(){

}

template <class T>
bool listasinglepointer<T>::listaVuota() const{
    return (lenght == 0);
}

template <class T>
typename listasinglepointer<T>::value_type listasinglepointer<T>::leggiLista(position p) const{
    if(!fineLista(p)){
        return p->value;

    }

}

template <class T>
void listasinglepointer<T>::scriviLista(const value_type &a,position p) {
    if(!fineLista(p))
        p->value = a;
}

template <class T>
typename listasinglepointer<T>::position listasinglepointer<T>::primoLista() const{
    return head->succ;
}

template <class T>
bool listasinglepointer<T>::fineLista(position p) const {
    return (p == head);
}

template <class T>
typename listasinglepointer<T>::position listasinglepointer<T>::succLista(position p) const{
    return p->succ;
}


template <class T>
typename listasinglepointer<T>::position listasinglepointer<T>::predLista(position p) const{
    position prev = p;
    for(int i = 0; i < lenght  ; i++){
        prev = prev->succ;
    }
    return prev;

}

template <class T>
void listasinglepointer<T>::insLista(const value_type a,position p) {
    position prev;
    position t = new cella<T>;
    t->value = a;
    t->succ = p; 
    prev = predLista(p);
    prev->succ = t;
    lenght ++;
}

template <class T>
void listasinglepointer<T>::cancLista(position p) {

    position prev = nullptr;
    if(!listaVuota() && !fineLista(p)){
        prev = predLista(p);
        prev->succ = p->succ;
        delete[] p;
        lenght --;
    }

}

template<class T>
listasinglepointer<T>& listasinglepointer<T>::operator=(const listasinglepointer<T>& L){
    if (this != &L){
        head = new cella<T>;
        head->succ = head;
        
        if (!L.listaVuota()){
            position p = L.predLista(L.head);
            for (int i=0; i < L.lenght; i++){
                cout << i, L.leggiLista(p);
                insLista(L.leggiLista(p),primoLista());
                p = L.predLista(p);
            }
        }
    }
    return *this;
}


template<class T>
bool listasinglepointer<T>::operator==(const listasinglepointer<T> &L) const{
   if (L.lunghezza() != lenght)
        return false;
    position p, pL;
    p = primoLista();
    pL = L.primoLista();
    while (!fineLista(p)){
        if (p->value != pL->value)
            return false;
        p = p->succ;
        pL = succLista(pL);
    }
    return true;
}


#endif //ASD_LISTASINGLEPOINTER_H
