//
// Created by arcangelo on 10/23/18.
//
#include <iostream>
#include "codePointer.h"

using namespace std;
int main (){
    codePointer<int> C(3);

    C.incoda(1);
    C.incoda(2);
    C.incoda(3);
    C.incoda(4);

    cout << " " << C.leggicoda();
    C.fuoricoda();
    C.incoda(4);
    cout << " " << C.leggicoda();
    C.fuoricoda();
    cout << " " << C.leggicoda();
    C.incoda(5);
    C.fuoricoda();
    cout << " " << C.leggicoda();
    C.fuoricoda();
    cout << " " << C.leggicoda();
    C.fuoricoda();
    cout << endl;
    return 0;
}
