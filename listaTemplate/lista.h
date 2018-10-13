//
// Created by arcangelo on 10/11/18.
//

#ifndef C_LISTA_H
#define C_LISTA_H

template <class T,typename P>
class listalineare{
public:
    typedef t tipoelem;
    typedef p posizione;
    //distruttore
    virtual ~listalineare() {};
    //operatori
    virtual void creaLista();
    virtual bool listaVuota() const;
    virtual tipoelem leggiLista(posizione) const;
    virtual void scriviLista(tipoelem,posizione);
    virtual posizione primoLista() const;
    virtual bool fineLista(posizione) const;
    virtual posizione succLista(posizione) const;
    virtual posizione predLista(posizione) const;
    virtual void insLista(tipoelem,posizione);
    virtual void cancLista(posizione);
};

#endif //C_LISTA_H
