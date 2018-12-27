//
// Created by arcangelo on 10/13/18.
//

#ifndef ASD_LISTAVECTOR_H
#define ASD_LISTAVECTOR_H


#define DIMENSIONE 1024

#include "lista.h"


template <class T>
class listaVector;

template <class T>
class cella {
public:
    friend class listaVector<T>;
    cella<T> operator<(const cella<T>& c ) const { return this->value < c.value; };
    cella<T> operator<=(const cella<T>& c) const { return this->value <= c.value; };
    cella<T> operator>(const cella<T>& c) const { return this->value > c.value; };
private:
    T value;
};


template <class T>
class listaVector : public listalineare<T,int>{
public:
    typedef typename listalineare<T, int>::value_type value_type;
    typedef typename listalineare<T, int>::position position;
    listaVector();
    //distruttore
     ~listaVector() { delete elementi; };
    //operatori
     void creaLista();
     bool listaVuota() const;
    value_type leggiLista(int c) const;
     void scriviLista(const value_type &value,int c);
     int primoLista() const;
     bool fineLista(int) const;
     int succLista(int) const;
     int predLista(int) const;
     void insLista(value_type value,int);
    void cancLista(int);

    // sovraccarico di operatori
    listaVector<T>& operator=(const listaVector<T>&); // the assignment operator
    bool operator==(const listaVector<T> &) const; // tests two list for equality

private:
    int lenght;
    value_type* elementi;
};

template <class T>
listaVector<T>::listaVector(){
    listaVector<T>::creaLista();
}

template <class T> void listaVector<T>::creaLista() {
    this->elementi = new T[DIMENSIONE];
    this->lenght = 0;
}

template <class T> bool listaVector<T>::listaVuota() const{
    return(this->lenght == 0);
}

template <class T> typename listaVector< T >::value_type listaVector<T>::leggiLista(int c) const{
    if((0<= c) && (c < lenght+1) )
        return (elementi[c-1]);
    else
        throw "no valid position";
}

template <class T> void listaVector<T>::scriviLista(const value_type &value,int c){
    if((0<= c) && (c < lenght+1) )
        elementi[c-1] = value;
    else
        throw "no valid position";
}

template <class T> int listaVector<T>::primoLista() const{
    return(1);
}

template <class T> bool listaVector<T>::fineLista(int c) const{
    if((0< c) && (c <= lenght+1) )
        return (c == lenght+1);
    else
        return false;
}

template <class T> int listaVector<T>::succLista(int c) const{
    if((0< c) && (c < lenght+1) )
        return c+1;
    else
        return c;
}

template <class T> int listaVector<T>::predLista(int c) const{
    if((1< c) && (c < lenght+1) )
        return c-1;
    else
        return c;
}

template <class T> void listaVector<T>::insLista(value_type value,int c){
    if((0< c) && (c < lenght+1) )
        for(int i = lenght; i>= c; i--){
            elementi[i] = elementi[i-1];
        }
        elementi[c-1] = value;
        lenght ++;
}

template <class T> void listaVector<T>::cancLista(int c){
    if((0< c) && (c < lenght+1) )
        if(!listaVuota())
            for(int i = c-1; i < (lenght-1);i++ ) elementi[i] = elementi[i+1];
            lenght --;

}



template<class T>
listaVector<T>& listaVector<T>::operator=(const listaVector<T>& L){
    if (this != &L){   // attenzione agli autoassegnamenti: l = l
        this->lenght = L.lenght;
        delete this->elementi;
        this->elementi = new T[DIMENSIONE];
        for (int i=0; i< DIMENSIONE; i++)
            this->elementi[i] = L.elementi[i];
    }
    return *this;
}


template<class T>
bool listaVector<T>::operator==(const listaVector<T> &L) const{
    if (L.lunghezza() != lenght)
        return false;
    for (int i=0; i< DIMENSIONE; i++)
        if (this->elementi[i] != L.elementi[i])
            return false;
    return true;
}


#endif //ASD_LISTAVECTOR_H
