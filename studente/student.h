#ifndef STUDENT_H
#define STUDENT_H
#include<iostream> 
#include <string>
using namespace std;
class Student{

    public:
    //Student();
    Student(int matricola,int eta,string nome ,string cognome);
    bool checkMat(int matricola);//tra 255312 e 499999
    bool checkEta(int eta);//tra 12 e 105
    bool checkString(string value);//max 30 char
    template<typename T> void print(T value);

    private:
        int matricola;
        int eta;
        string nome;
        string cognome;
};

    template<typename T> void Student::print(T value)
    {
        cout << value;
    }


#endif