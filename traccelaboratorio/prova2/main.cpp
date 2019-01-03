//
// Created by arcangelo on 02/01/19.
//



#include <iostream>
using namespace std;
#include "../../alberibinari/alberiPuntatori.h"
#include "richieste.h"

int main(){
    richieste rich;
    alberiPuntatori<int> tree;
    alberiPuntatori<int> T;
    typename alberiPuntatori<int>::Nodo n1, n2;
    typename alberiPuntatori<int>::value_type v1;

    v1 = 1;

    T.ins_root(n1);
    T.write(T.root(),1);
    n1 = T.root();
    T.ins_sx(n1);
    T.ins_dx(n1);
    T.write(T.sx(n1),2);
    n1 = T.dx(n1);
    T.write(n1, 3);
    T.ins_dx(n1);
    T.write(T.dx(n1), 4);

    cout << rich.maxLevelSum(T);
    return 0;
}