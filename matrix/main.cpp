//
// Created by arcangelo on 10/11/18.
//
#include <iostream>

using namespace std;

#include "matrix.h"

int main(){

    Matrix matrice(3,4);
    //Matrix trasp(4,4);
    //matrice.~Matrix();
    //trasp.~Matrix();
    matrice.setElemento(2,3,12);
    //cout << matrice.printElemento(2,3) << endl;
    Matrix trasp(matrice.trasposta())  ;
    cout << trasp.printElemento(3,2) << endl;

    return 0;

}

