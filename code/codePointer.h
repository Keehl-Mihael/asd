//
// Created by arcangelo on 10/23/18.
//

#ifndef TEST_BUILD_CODEPOINTER_H
#define TEST_BUILD_CODEPOINTER_H

#include "code.h"


template <class T>
class codePointer;

template <class T>
class cella {
public:
    friend class codePointer<T>;
    cella<T> operator<(const cella<T>& c ) const { return this->value < c.value; };
    cella<T> operator<=(const cella<T>& c) const { return this->value <= c.value; };
    cella<T> operator>(const cella<T>& c) const { return this->value > c.value; };
    cella<T> operator=(const cella<T>* c) const {
        this->value = c->value;
        this->succ = c->succ;
    };
private:
    T value;
    cella<T> * succ;
};

template <class T>
class codePointer: public code<T>{
private:
    typedef typename code<T>::value_type value_type;
    cella<T>* head;
    cella<T>* tail;
    int lenght;
public:

    codePointer(){
        creacoda();
    }


    void creacoda(){
        head = new cella<T>;
        tail = head;
        lenght = 0;
    };

    bool codavuota(){
        return (lenght == 0);
    };

    value_type leggicoda(){
        return head->succ->value;
    };
    void fuoricoda(){
        cella<T>* temp;
        temp = head;
        head = head->succ;
    delete[] temp;
        lenght --;
    };
    void incoda(value_type v){
        cella<T>* incella;
        tail->succ = incella;        
        incella->value = v ;
        incella->succ = 0;
        tail = incella;
        lenght ++;
    }; //aggiungi const

};



#endif //TEST_BUILD_CODEPOINTER_H
