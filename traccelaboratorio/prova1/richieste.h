//
// Created by siroid on 1/1/19.
//

#ifndef TEST_BUILD_RICHIESTE_H
#define TEST_BUILD_RICHIESTE_H

#include <map>

class richieste{
private:
    map<int,int> mymap;
public:
    typedef typename listPointer<int>::position position;
    typedef typename listPointer<int>::value_type value_type;

    int freq(listPointer<int> &L, int k){
        position p1;
        p1 = L.primoLista();
        int counter = 0;
        value_type v;
        while(!L.fineLista(p1)){
            v = L.leggiLista(p1);
            if((v % k) == 0){
                counter ++;
            }
            p1 = L.succLista(p1);
        }
        return counter;

    }

    void hits(listPointer<int> &L){
        mymap.clear();
        position p1;
        p1 = L.primoLista();
        value_type v;
        while(!L.fineLista(p1)){
            v = L.leggiLista(p1);
            mymap[v] ++;
            p1 = L.succLista(p1);
        }
        cout << "mymap contains:\n";
        for (map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            cout << it->first << " => " << it->second << '\n';

    }

    void remp(listPointer<int> &L){
        position p1,p2;
        p1 = L.primoLista();
        int counter = 0;
        value_type v1,v2;
        while(!L.fineLista(p1)){
            v1 = L.leggiLista(p1);
            p2 = L.succLista(p1);
            v2 = L.leggiLista(p2);
            if((v2 % 2) != 0){
                L.cancLista(p1);
            }
            p1 = L.succLista(p1);
        }
    }


};


#endif //TEST_BUILD_RICHIESTE_H
