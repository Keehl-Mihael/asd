#include<iostream> 
#include <string>
#include "student.h"
using namespace std;




    
    

    Student::Student(int matricola,int eta,string nome,string cognome ){
        
        try{

            Student::checkMat(matricola);
            Student::checkEta(eta);
            Student::checkString(nome);
            Student::checkString(cognome);
        }catch(char const* stringExc){
            cerr << "Error: " << stringExc << endl;
        }
    }

    bool Student::checkMat(int matricola){
        if(matricola < 25513 || matricola > 499999){
            throw "matricola not valid";
        }
        return true;
    }

    bool Student::checkEta(int eta){
        if(eta < 12 || eta > 105){
            throw "eta not valid";
        }
        return true;
    }
    bool Student::checkString(string value){
        if(value.length() < 1 || value.length() > 30){
            throw "string not valid";
        }
        return true;
    }


