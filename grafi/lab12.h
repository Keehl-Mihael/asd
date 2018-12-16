//
// Created by siroid on 12/16/18.
//

#ifndef TEST_BUILD_LAB12_H
#define TEST_BUILD_LAB12_H


template <class T>
class lab12{
public:

    typedef typename T::ListaNodi ListaNodi;
    typedef typename T::Nodo Nodo;

    lab12(){}

    lab12(T incoming){
        grafo = incoming;
    }

    int inDegree(Nodo n){
        int count = 0;
        ListaNodi l = grafo.Adiacenti(n);
        //da continuare
        return count;
    }

private:
    T grafo;
};



#endif //TEST_BUILD_LAB12_H
