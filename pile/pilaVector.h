#ifndef PILAVECTOR_H
#define PILAVECTOR_H

template <class t>
class pilavector;
//implementare la classe nodo

#define MAXLUNG = 10;

template <class T>
class pilavector : public pila <T>{
public:
    pila(){
        creapila();
    };
    ~pila(){

    };
    void creapila(){
        testa = 0;
    };
    bool pilavuota(){
        return (testa == 0);
    };
    value_type leggipila(){
        return elements[testa];
    };
    void fuoripila(){
        if(!pilavuota())
            testa -=1;
        else
            throw "la pila è vuota";
    };
    void inpila(value_type t){
        if(testa == MAXLUNG){
            //possibilità di implementare estensione della pila attuale
            throw "la pila è piena";
        }else{
            elements[testa] = t;
            testa ++;
        }
    };
private:
    int testa;
    value_type elements[MAXLUNG];

};

#endif //PILAVECTOR_H