//
// Created by siroid on 12/16/18.
//

#ifndef TEST_BUILD_LAB12_H
#define TEST_BUILD_LAB12_H

#include "../codepriority/codap.h"

template <class T>
class lab12{
public:

    typedef typename T::ListaNodi ListaNodi;
    typedef typename T::Nodo Nodo;
    typedef typename T::ListaNodiPos p;



    static int outDegree(T &grafo,Nodo n){
        int count = 0;
        ListaNodi l = grafo.Adiacenti(n);
        p start = l.begin();
        while(!l.end(start)){
            start = l.next(start);
            count ++;
        }
        return count;
    }

    static int inDegree(T &grafo,Nodo n){
        int count = 0; ListaNodi ad;p start2;
        ListaNodi l = grafo.list_nodi();
        p start = l.begin();
        while(!l.end(start)){
            ad = grafo.Adiacenti(start);
            start2= ad.begin();
            while(!ad.end(start2)){
                if( n.getId() == (ad.read(start2))->getId()){
                    count ++;
                }
                start2 = ad.next(start2);
            }
            start = l.next(start);
        }
        return count;
    }

    static double meanOutDegree(T &grafo){
        ListaNodi l = grafo.list_nodi();
        int num_nodi=0,sum_archi_usc=0;
        p start = l.begin();
        while(!l.end(start)){
            sum_archi_usc += inDegree(grafo,*(l.read(start)));
            start = l.next(start);
            num_nodi ++;
        }
        return sum_archi_usc/num_nodi;
    }

/*    static bool findPath(T &grafo,Nodo s,Nodo d){
        CodaP<Nodo> c;
        int nodi[grafo.numNodi()];
        nodi
        return false;
    }*/


};



#endif //TEST_BUILD_LAB12_H
