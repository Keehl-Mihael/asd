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


};



#endif //TEST_BUILD_LAB12_H
