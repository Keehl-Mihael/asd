//
// Created by arcangelo on 10/13/18.
//

#ifndef ASD_LISTACURSORI_H
#define ASD_LISTACURSORI_H

typedef int cursor;
#define DIMENSIONE 1024

#include "lista.h"


template <class T,typename P>
class listaCursori : public listalineare<T,cursor>{
public:
    listaCursori();
    //distruttore
     ~listaCursori() {};
    //operatori
     void creaLista();
     bool listaVuota() const;
     T leggiLista(cursor c) const;
     void scriviLista(T value,cursor c);
     cursor primoLista() const;
     bool fineLista(cursor) const;
     cursor succLista(cursor) const;
     cursor predLista(cursor) const;
     void insLista(T,cursor);
    void cancLista(cursor);

private:
    int lunghezza;
    T* elementi[DIMENSIONE];
};

template <class T,typename P>
listaCursori<T,P>::listaCursori(){
   // creaLista();
}

template <class T,typename P> void listaCursori<T,P>::creaLista() {
    lunghezza = 0;
    for (int i = 0; i < DIMENSIONE; ++i) {

        elementi[i] = new T[3];
        elementi[i][0] = i - 1;
        elementi[i][1] = i;
        elementi[i][2] = i + 1;
    }

}

template <class T,typename P> bool listaCursori<T,P>::listaVuota() const{
    return(lunghezza == 0);
}

template <class T,typename P> T listaCursori<T,P>::leggiLista(cursor c) const{
    return(elementi[c][1]);
}

template <class T,typename P> void listaCursori<T,P>::scriviLista(T value,cursor c){
    elementi[c][1]=value;
}

template <class T,typename P> cursor listaCursori<T,P>::primoLista() const{
   int i;
   cursor x;
   for(i=0;i<lunghezza;i++)
       if(elementi[i][0] == -1)
           x=i;
           return x;
}

template <class T,typename P> bool listaCursori<T,P>::fineLista(cursor c) const{
    if(elementi[c][2] == lunghezza -1)
        return true;
    return false;
}

template <class T,typename P> cursor listaCursori<T,P>::succLista(cursor c) const{
    return elementi[c][2];
}

template <class T,typename P> cursor listaCursori<T,P>::predLista(cursor c) const{
    return elementi[c][1];
}

template <class T,typename P> void listaCursori<T,P>::insLista(T value,cursor c){
    cursor temp;
    elementi[c][0] = c-1;
    temp = elementi[elementi[c][0]][2];
    elementi[elementi[c][0]][2] = c;
    elementi[c][2] = temp;
    elementi [c][1] = value;
    elementi[elementi[c][2]][0] = c;
    lunghezza ++;
}

template <class T,typename P> void listaCursori<T,P>::cancLista(cursor c){
    lunghezza --;

    elementi[c-1][2] = elementi[c][0];
    elementi[c + 1][0] = c-1;

    elementi[c][0] = 0;
    elementi[c][1] = 0;
    elementi[c][2] = 0;


}


#endif //ASD_LISTACURSORI_H
