//
// Created by arcangelo on 10/18/18.
//

#ifndef ASD_LISTAPOINTER_H
#define ASD_LISTAPOINTER_H

#include "lista.h"


template <class T>
class listPointer;

template <class T>
class cella {
public:
    friend class listPointer<T>;
    cella<T> operator<(const cella<T>& c ) const { return this->value < c.value; };
    cella<T> operator<=(const cella<T>& c) const { return this->value <= c.value; };
    cella<T> operator>(const cella<T>& c) const { return this->value > c.value; };
private:
    T value;
    cella<T> * prev;
    cella<T> * succ;
};


template <class T>
class listPointer: public listalineare <T,cella<T>*> {
private:
    cella<T>* head;
    int lenght;
public:

    typedef typename listalineare<T, cella<T>*>::value_type value_type;
    typedef typename listalineare<T, cella<T>*>::position position;

    listPointer();
    ~listPointer();
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
    int lunghezza() const;
    void inverti() ;
    bool palindroma() ;

    // sovraccarico di operatori
    listPointer<T>& operator=(const listPointer<T>&); // the assignment operator
    bool operator==(const listPointer<T> &) const; // tests two list for equality

};



template <class T>
listPointer<T>::listPointer(){
    head = new cella<T>;
    head-> prev = head;
    head-> succ = head;
    lenght = 0;
}

template <class T>
listPointer<T>::~listPointer(){
    while(!listaVuota())
        cancLista(primoLista());
    delete head;
}

template <class T>
void listPointer<T>::creaLista() {
    if(listaVuota()){
        lenght = 0;
    }
}
template <class T>
int listPointer<T>::lunghezza() const {
    return (lenght);
}

template <class T>
bool listPointer<T>::palindroma(){
    int i;
        position p_start, p_end;
        p_start = succLista(head);
        p_end = predLista(head);
        for(i = 0; i <= (int)lenght+1/2; i++){
            if(p_start->value != p_end->value)
                return false;
            else
                p_end = predLista(p_end);
                p_start = succLista(p_start);

        }


    return (true);
}

template <class T>
void listPointer<T>::inverti(){
    int i;
    T temp ;
    position p_start, p_end;
    p_start = succLista(head);
    p_end = predLista(head);
    for(i = 0; i <= (int)lenght+1/2; i++){
        temp = p_start->value;
        p_start->value = p_end->value;
        p_end->value = temp;
        p_end = predLista(p_end);
        p_start = succLista(p_start);
    }


}

template <class T>
bool listPointer<T>::listaVuota() const{
    return (lenght == 0);
}

template <class T>
typename listPointer<T>::value_type listPointer<T>::leggiLista(position p) const{
    if(!fineLista(p)){
        return p->value;

    }

}

template <class T>
void listPointer<T>::scriviLista(const value_type &a,position p) {
    if(!fineLista(p))
        p->value = a;
}

template <class T>
typename listPointer<T>::position listPointer<T>::primoLista() const{
    return head->succ;
}

template <class T>
bool listPointer<T>::fineLista(position p) const {
    return (p == head);
}

template <class T>
typename listPointer<T>::position listPointer<T>::succLista(position p) const{
    return p->succ;
}

template <class T>
typename listPointer<T>::position listPointer<T>::predLista(position p) const{
    return p->prev;
}

template <class T>
void listPointer<T>::insLista(const value_type a,position p) {

    position t = new cella<T>;
    t->value = a;
    t->succ = p;
    t->prev = p->prev;
    p->prev->succ = t;
    p->prev = t;

    lenght ++;
}

template <class T>
void listPointer<T>::cancLista(position p) {
    if(!listaVuota() && !fineLista(p))
        p->prev->succ = p->succ;
        p->succ->prev = p->prev;
        delete[] p;
        lenght --;
}

template<class T>
listPointer<T>& listPointer<T>::operator=(const listPointer<T>& L){
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
bool listPointer<T>::operator==(const listPointer<T> &L) const{
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
