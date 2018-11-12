//
// Created by arcangelo on 10/13/18.
//

#ifndef ASD_LISTACURSORI_H
#define ASD_LISTACURSORI_H

typedef int cursor;
#define DIMENSIONE 1024

#include "lista.h"


template <class T>
class listaCursori : public listalineare<T,cursor>{
public:
    listaCursori();
    //distruttore
     ~listaCursori() {};
    //operatori
     void creaLista();
     bool listaVuota() const;
     T leggiLista(cursor c) const;
     void scriviLista(const T &value,cursor c);
     cursor primoLista() const;
     bool fineLista(cursor) const;
     cursor succLista(cursor) const;
     cursor predLista(cursor) const;
     void insLista(T,cursor);
    void cancLista(cursor);
    int lunghezza() const;
    void inverti();
    bool palindroma();

    // sovraccarico di operatori
    listaCursori<T>& operator=(const listaCursori<T>&); // the assignment operator
    bool operator==(const listaCursori<T> &) const; // tests two list for equality

private:
    int lenght;
    T* elementi[DIMENSIONE];
};

template <class T>
listaCursori<T>::listaCursori(){
   // creaLista();
}

template <class T> void listaCursori<T>::creaLista() {
    this->lenght = 0;
    for (int i = 0; i < DIMENSIONE; ++i) {

        elementi[i] = new T[3];
        elementi[i][0] = i - 1;
        elementi[i][1] = -1;
        elementi[i][2] = i + 1;
    }

}

template <class T> bool listaCursori<T>::listaVuota() const{
    return(this->lenght == 0);
}

template <class T> T listaCursori<T>::leggiLista(cursor c) const{
    return(elementi[c][1]);
}

template <class T> void listaCursori<T>::scriviLista(const T &value,cursor c){
    elementi[c][1]=value;
}

template <class T> cursor listaCursori<T>::primoLista() const{
   int i;
   cursor x;
   for(i=0;i<this->lenght;i++)
       if(elementi[i][0] == -1){
           x=i;
           return x;
       }
}

template <class T> bool listaCursori<T>::fineLista(cursor c) const{
    if(elementi[c][2] == this->lenght -1)
        return true;
    return false;
}

template <class T> cursor listaCursori<T>::succLista(cursor c) const{
    return elementi[c][2];
}

template <class T> cursor listaCursori<T>::predLista(cursor c) const{
    return elementi[c][1];
}

template <class T> void listaCursori<T>::insLista(T value,cursor c){
    cursor temp;
    elementi[c][0] = c-1;
    temp = elementi[elementi[c][0]][2];
    elementi[elementi[c][0]][2] = c;
    elementi[c][2] = temp;
    elementi [c][1] = value;
    elementi[elementi[c][2]][0] = c;
    this->lenght ++;
}

template <class T> void listaCursori<T>::cancLista(cursor c){
    this->lenght --;

    elementi[c-1][2] = elementi[c][0];
    elementi[c + 1][0] = c-1;

    elementi[c][0] = 0;
    elementi[c][1] = 0;
    elementi[c][2] = 0;


}

template < class T>
int listaCursori<T>::lunghezza() const{
     return this->lenght;
}

template < class T>
void listaCursori<T>::inverti() {

}

template < class T>
bool listaCursori<T>::palindroma() {

}


template<class T>
listaCursori<T>& listaCursori<T>::operator=(const listaCursori<T>& L){
/*    if (this != &L){   // attenzione agli autoassegnamenti: l = l
        this->lenght = L.lenght;
        delete this->elementi;
        this->elementi = new T[DIMENSIONE];
        for (int i=0; i< DIMENSIONE; i++)
            this->elementi[i] = L.elementi[i];
    }
    return *this;*/
}


template<class T>
bool listaCursori<T>::operator==(const listaCursori<T> &L) const{
/*    if (L.lunghezza() != lenght)
        return false;
    for (int i=0; i< DIMENSIONE; i++)
        if (this->elementi[i] != L.elementi[i])
            return false;*/
    return true;
}


#endif //ASD_LISTACURSORI_H
