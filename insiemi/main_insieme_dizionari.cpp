//
// Created by arcangelo on 05/11/18.
//

#include <iostream>

#include "insiemeListeOrdinate.h"


using namespace std;

int main(){

    insiemeList<int> list;
    insiemeList<int>::value_type  v;
    v = 10;



    list.crea();

    list.inserisci(v);




    return 0;

}

