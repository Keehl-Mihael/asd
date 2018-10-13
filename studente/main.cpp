#include<iostream> 

#include <string>
#include "student.h"

using namespace std;

int main(){

    int matricola = 30000,eta=12;
    string name="arc" ,surname="sar";

    //Student();
    
    Student student(matricola,eta,name,surname);
    cout << "matricola: ";
    student.print(matricola);
    cout << "\t eta: ";
    student.print(eta);
    cout << "\t nome: ";
    student.print(name);
    cout << "\t cognome: ";
    student.print(surname);
    cout << endl;

    return 0;
}