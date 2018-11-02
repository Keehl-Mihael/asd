//
// Created by arcangelo on 10/18/18.
//

#ifndef ASD_LISTASINGLEPOINTERFLAG_H
#define ASD_LISTASINGLEPOINTERFLAG_H

#include "listaSinglePointer.h"



template <class T>
class listasinglepointerflag : public listasinglepointer<T>{

public :
    typedef typename listasinglepointer<T>::value_type value_type;
    typedef typename listasinglepointer<T>::position position;
    void insLista(const value_type &a, position  p){
      if(!listasinglepointer<T>::fineLista(p)){
          listasinglepointer<T>::insLista(a,p);
      }else{
        position prev;
        position t = new cella<T>;
        t->value = a;
        t->succ = listasinglepointer<T>::head;
        prev = listasinglepointer<T>::predLista(p);
        prev->succ = t;
          listasinglepointer<T>::lenght ++;
      }
    }
    void cancLista(position p){
      if(!listasinglepointer<T>::fineLista(p)){
          listasinglepointer<T>::cancLista(p);
      }else{
            position prev = nullptr;
            if(!listasinglepointer<T>::listaVuota()){
                prev = listasinglepointer<T>::predLista(p);
                prev->succ = listasinglepointer<T>::head;
                delete[] p;
                listasinglepointer<T>::lenght --;
            }

      }
    }
  
};

#endif // ASD_LISTASINGLEPOINTERFLAG_H
