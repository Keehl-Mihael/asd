//
// Created by arcangelo on 10/11/18.
//
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#ifndef C_LISTA_H
#define C_LISTA_H

template <class T,class P>
class listalineare{
public:
    typedef T value_type;
    typedef P position;
    //distruttore
    virtual ~listalineare() {};
    //operatori
    virtual void creaLista() = 0;
    virtual bool listaVuota() const = 0;
    virtual value_type leggiLista(position) const = 0;
    virtual void scriviLista(const value_type &x,position) = 0;
    virtual position primoLista() const = 0;
    virtual bool fineLista(position) const = 0;
    virtual position succLista(position) const = 0 ;
    virtual position predLista(position) const = 0;
    virtual void insLista(value_type,position) = 0;
    virtual void cancLista(position) = 0;
    virtual int lunghezza() const = 0;
    virtual void inverti() = 0;
    virtual bool palindroma() = 0;
};

/* sovraccarica <<. Attenzione se il tipo restituito da read non è primitivo, allora
 * anche per questo tipo bisogna sovraccaricare l'operatore <<
 */
template< class T, class P >
ostream& operator<<(ostream& os, const listalineare<T,P> &l){
    typename listalineare<T,P>::position p;
    p = l.primoLista();
    os << "[";
    while (!l.fineLista(p)){
        if (p != l.primoLista())
            os << ", " << l.leggiLista(p);
        else
            os << l.leggiLista(p);
        p = l.succLista(p);
    }
    os << "]" << endl;
    return os;
}

#endif //C_LISTA_H
