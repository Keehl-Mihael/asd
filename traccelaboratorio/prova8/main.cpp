//
// Created by siroid on 1/1/19.
//

#include <iostream>
using namespace std;
#include "richieste.h"

int main(){
    Bilanciate<char> rich;

    try {
        rich.test("for (i=0) to 10");
        rich.test("(3+2)/[3-(2-1)]");
        rich.test("{1-(3+2)/[3-(2-1)]}");
        rich.test("{1-(3+2)/[3-(2-1))]}");
        rich.test("{{1-(3+2)/([3-(2-1)]}");
        rich.test("{1-(3+2)/([3-(2-1)]");

    }catch (string e){
        cerr << e << endl;
    }




    return 0;
}