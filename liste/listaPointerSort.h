//
// Created by arcangelo on 10/18/18.
//

#ifndef ASD_LISTAPOINTER_H
#define ASD_LISTAPOINTER_H

#include "lista.h"


template <class T>
class listPointerSort;

template <class T>
class cella {
public:
    friend class listPointerSort<T>;
    cella<T> operator<(const cella<T>& c ) const { return this->value < c.value; };
    cella<T> operator<=(const cella<T>& c) const { return this->value <= c.value; };
    cella<T> operator>(const cella<T>& c) const { return this->value > c.value; };
private:
    T value;
    cella<T> * prev;
    cella<T> * succ;
};


template <class T>
class listPointerSort: public listalineare <T,cella<T>*> {
private:
    cella<T>* head;
    int lenght;
public:

    typedef typename listalineare<T, cella<T>*>::value_type value_type;
    typedef typename listalineare<T, cella<T>*>::position position;

    listPointerSort();
    ~listPointerSort();
    void creaLista();
    bool listaVuota() const;
    value_type leggiLista(position) const;
    value_type leggiLista(value_type &p) ;
    void scriviLista(const value_type &a,position);
    position primoLista() const;
    bool fineLista(position) const;
    position succLista(position) const;
    position predLista(position) const;
    void insLista(value_type,position);
    void cancLista(position);


    // sovraccarico di operatori
    listPointerSort<T>& operator=(const listPointerSort<T>&); // the assignment operator
    bool operator==(const listPointerSort<T> &) const; // tests two list for equality

};



template <class T>
listPointerSort<T>::listPointerSort(){
    head = new cella<T>;
    head-> prev = head;
    head-> succ = head;
    lenght = 0;
}

template <class T>
listPointerSort<T>::~listPointerSort(){
    while(!listaVuota())
        cancLista(primoLista());
    delete head;
}

template <class T>
void listPointerSort<T>::creaLista() {
    if(listaVuota()){
        lenght = 0;
    }
}





template <class T>
bool listPointerSort<T>::listaVuota() const{
    return (lenght == 0);
}

template <class T>
typename listPointerSort<T>::value_type listPointerSort<T>::leggiLista(position p) const{
    if(!fineLista(p)){
        return p->value;
    }

}

template <class T>
typename listPointerSort<T>::value_type listPointerSort<T>::leggiLista(value_type &p) {
    position iter = 0;
    while(!fineLista(iter)){
        if(p == succLista(iter)->value){
            return succLista(iter)->value;
        }
        iter++;
    }
    throw ("not in list");
}

template <class T>
void listPointerSort<T>::scriviLista(const value_type &a,position p) {
    if(!fineLista(p))
        p->value = a;
}

template <class T>
typename listPointerSort<T>::position listPointerSort<T>::primoLista() const{
    return head->succ;
}

template <class T>
bool listPointerSort<T>::fineLista(position p) const {
    return (p == head);
}

template <class T>
typename listPointerSort<T>::position listPointerSort<T>::succLista(position p) const{
    return p->succ;
}

template <class T>
typename listPointerSort<T>::position listPointerSort<T>::predLista(position p) const{
    return p->prev;
}

template <class T>
void listPointerSort<T>::insLista(const value_type a,position p) {

    position t = new cella<T>;
    t->value = a;

    position next = new cella<T>;
    next = head;
    if(next->succ == NULL || next->value >= t->value){
        t->succ = next;
        t->prev = next->prev;
        next->prev->succ = t;
        next->prev = t;
    }else{
        next = succLista(head);
        while(next->succ != NULL && t->value < next->value){
            next = succLista(next);
        }
        t->succ = next;
        t->prev = next->prev;
        next->prev->succ = t;
        next->prev = t;
    }



    lenght ++;
}

template <class T>
void listPointerSort<T>::cancLista(position p) {
    if(!listaVuota() && !fineLista(p))
        p->prev->succ = p->succ;
        p->succ->prev = p->prev;
        delete[] p;
        lenght --;
}

template<class T>
listPointerSort<T>& listPointerSort<T>::operator=(const listPointerSort<T>& L){
    if (this != &L){
        head = new cella<T>;
        head->succ = head;
        head->prev = head;

        if (!L.listaVuota()){
            position p = L.head->prev;
            for (int i=0; i < L.lenght; i++){
                cout << i, L.leggiLista(p) ;
                insLista(L.leggiLista(p), primoLista());
                p = L.predLista(p);
            }
            cout << endl;
        }
    }
    return *this;
}


template<class T>
bool listPointerSort<T>::operator==(const listPointerSort<T> &L) const{
   if (L.lunghezza() != lenght)
        return false;
    position p, pL;
    p = primoLista();
    pL = L.primoLista();
    while (!fineLista(p)){
        if (p->value != pL->value)
            return false;
        p = p->succ;
        pL = pL->succ;
    }
    return true;
}


#endif //ASD_LISTAPOINTER_H
