//
// Created by siroid on 1/1/19.
//

#include <iostream>
using namespace std;
#include "../../liste/listaPointer.h"
#include "richieste.h"

int main(){


    listPointer<int> list1;
    listPointer<int>::position iter;
    richieste<int,cella<int>*> rich;

    int x;

    /* inserting three elements into the list list1 */
    x = 1;
    list1.insLista(x, list1.primoLista());

    x = 2;
    list1.insLista(x, list1.primoLista());

    x = 2;
    list1.insLista(x, list1.primoLista());
    x = 3;
    list1.insLista(x, list1.primoLista());


    x = 4;
    list1.insLista(x, list1.primoLista());

    x = 6;
    list1.insLista(x, list1.primoLista());
    x = 6;
    list1.insLista(x, list1.primoLista());

    cout << "freq multipli di 1 : " << rich.freq(list1,1) <<endl;
    rich.remp(list1);
    rich.hits(list1);

    return 0;
}