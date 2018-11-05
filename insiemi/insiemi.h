//
// Created by arcangelo on 05/11/18.
//

#ifndef INSIEMI_H
#define INSIEMI_H

template <class T>
class insieme{
public:
    typedef T value_type;
    virtual void crea();
    virtual bool vuoto();
    virtual bool appartiene(value_type &v)const;
    virtual void inserisci(value_type &v);
    virtual void cancella(value_type &v);
    virtual void unione(insieme &i); //esegue l'unione dell'insieme corrente a quello passato
    virtual void intersezione(insieme &i)//modifica l'insieme corrente eseguendo l'intersezione con l'insieme passato
    virtual void differenza(insieme &i)//modifica l'insieme corrente eseguendo la differenza con l'insieme passato
};

#endif //INSIEMI_H
