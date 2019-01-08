//
// Created by arcangelo on 02/01/19.
//



#include <iostream>
using namespace std;
#include "../../grafi/GrafoList.h"
#include "richieste.h"

int main(){
    richieste<int> rich;
    GrafoList<int,int> G(10);
    typedef typename GrafoList<string,double>::Nodo NodoG;



    NodoG n1,n2,n3,n4,n5,n6;

    G.insNodo(n1);
    G.scriviEtichetta(n1,1);
    G.insNodo(n2);
    G.scriviEtichetta(n2,3);
    G.insNodo(n3);
    G.scriviEtichetta(n3,5);
    G.insNodo(n4);
    G.scriviEtichetta(n4,4);
    G.insNodo(n5);
    G.scriviEtichetta(n5,6);
    G.insNodo(n6);
    G.scriviEtichetta(n6,2);



    G.insArco(n1,n2, 1);
    G.insArco(n1,n3, 9);
    G.insArco(n1,n5, 3);
    G.insArco(n2,n4, 1);
    G.insArco(n2,n6, 2);
    G.insArco(n3,n4, 10);
    G.insArco(n3,n6, 7);
    G.insArco(n4,n1, 5);
    G.insArco(n5,n2, 4);
    G.insArco(n5,n3, 2);
    G.insArco(n6,n4, 1);

    rich.printAllPaths(5,3);

    return 0;
}