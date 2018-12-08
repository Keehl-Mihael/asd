//
// Created by arcangelo on 05/11/18.
//

#ifndef INSIEMI_H
#define INSIEMI_H

template <class T,class P>
class insieme{
public:
    typedef T value_type;
    virtual void crea() = 0;
    virtual bool vuoto() = 0;
    virtual bool appartiene(value_type &v)const = 0;
    virtual void inserisci(value_type &v) = 0;
    virtual void cancella(value_type &v) = 0 ;
    virtual void unione(insieme &i) = 0; //esegue l'unione dell'insieme corrente a quello passato
    virtual void intersezione(insieme &i) = 0;//modifica l'insieme corrente eseguendo l'intersezione con l'insieme passato
    virtual void differenza(insieme &i) = 0;//modifica l'insieme corrente eseguendo la differenza con l'insieme passato
};

#endif //INSIEMI_H
