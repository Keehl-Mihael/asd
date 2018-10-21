//
// Created by arcangelo on 10/11/18.
//
#include <iostream>
#include "lista.h"
#include "listaCursori.h"


using namespace std;

int main(){
    typedef int cur;
    listaCursori<int> list;
    cur pos;


    list.creaLista();
    cout << list.primoLista() << endl;
    list.scriviLista(10,list.primoLista());
    cout << list.leggiLista(list.primoLista()) << endl;


    return 0;

}

