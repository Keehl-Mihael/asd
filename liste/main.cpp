//
// Created by arcangelo on 10/11/18.
//
#include <iostream>

#include "listaVector.h"


using namespace std;

int main(){

    listaVector<int> list;



    list.creaLista();
    cout << list.primoLista() << endl;
    list.scriviLista(10,0);
    cout << list.leggiLista(0);



    return 0;

}

