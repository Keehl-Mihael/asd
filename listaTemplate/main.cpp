//
// Created by arcangelo on 10/11/18.
//
#include <iostream>
#include "lista.h"
#include "listaCursori.h"


using namespace std;

int main(){
    typedef int cur;
    listaCursori<int*,cur> list();
    cur pos = 3;

    list().creaLista();
    cout << list().primoLista() << endl;
    list().scriviLista(10,pos);
    cout << list().leggiLista(pos) << endl;


    return 0;

}

