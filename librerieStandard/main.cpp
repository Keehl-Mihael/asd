//
// Created by arcangelo on 19/12/18.
//

#include <iostream>
#include <algorithm>
#include "grafoConHashMap.h"

using namespace std;

int main(){


    grafo<int> Grafo;

    cout << Grafo.vuoto();
    cout << endl;
    Grafo.insnodo(1);
    Grafo.insnodo(2);
    cout << endl;
    Grafo.insarco(1,2,10);
    //Grafo.cancnodo(1);
    Grafo.cancarco(1,2,10);

    return 0;
}