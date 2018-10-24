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
    listaVector();
    //distruttore
     ~listaVector() {};
    //operatori
     void creaLista();
     bool listaVuota() const;
     T leggiLista(int c) const;
     void scriviLista(const T &value,int c);
     int primoLista() const;
     bool fineLista(int) const;
     int succLista(int) const;
     int predLista(int) const;
     void insLista(T,int);
    void cancLista(int);
    int lunghezza();
    void inverti(){};
    bool palindroma(){ return true;};

private:
    int lenght;
    T elementi[DIMENSIONE];
};

template <class T>
listaVector<T>::listaVector(){
    listaVector<T>::creaLista();
}

template <class T> void listaVector<T>::creaLista() {
    this->lenght = 0;
}

template <class T> bool listaVector<T>::listaVuota() const{
    return(this->lenght == 0);
}

template <class T> T listaVector<T>::leggiLista(int c) const{
    if((0<= c) && (c < lenght+1) )
        return (elementi[c-1]);
    else
        throw "no valid position";
}

template <class T> void listaVector<T>::scriviLista(const T &value,int c){
    if((0<= c) && (c < lenght+1) )
        elementi[c-1] = value;
    else
        throw "no valid position";
}

template <class T> int listaVector<T>::primoLista() const{
    return(1);
}

template <class T> bool listaVector<T>::fineLista(int c) const{
    if((0< c) && (c < lenght+1) )
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

template <class T> void listaVector<T>::insLista(T value,int c){
    if((0< c) && (c < lenght+1) )
        for(int i = lenght; i>= c; i--) elementi[i] = elementi[i-1];
        elementi[c-1] = value;
        lenght ++;
}

template <class T> void listaVector<T>::cancLista(int c){
    if((0< c) && (c < lenght+1) )
        if(!listaVuota())
            for(int i = c-1; i < (lenght-1);i++ ) elementi[i] = elementi[i+1];
            lenght --;

}

template < class T>
int listaVector<T>::lunghezza() {
     return this->lenght;
}




#endif //ASD_LISTAVECTOR_H
