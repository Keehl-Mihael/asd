//
// Created by arcangelo on 14/12/18.
//

#ifndef TEST_BUILD_ALBERIPUNTATORI_H
#define TEST_BUILD_ALBERIPUNTATORI_H

#include "Bin_tree.h"

template <class T>
class alberiPuntatori;

template <class T>
class cella {
public:
    friend class alberiPuntatori<T>;
private:

    T value;
    cella<T> * sxn;
    cella<T> * dxn;
    cella<T> * father;
};

template <class T>
class alberiPuntatori: public Bin_tree<T,cella<T>*>{
private:
    cella<T>* _root;
    int lenght;
public:
    typedef typename Bin_tree<T, cella<T>*>::value_type value_type;
    typedef typename Bin_tree<T, cella<T>*>::Nodo Nodo;

    alberiPuntatori(){
        create();
    };
    ~alberiPuntatori(){
/*       while(!empty()){
            erase();
        }*/
        delete _root;
    };
    void create(){
        lenght = 0;
        _root = NULL;
    };
    bool empty() const{
        return (root() == NULL);
    };


    Nodo root() const{
        return this->_root;
    };
    Nodo parent(Nodo n) const{
        return n->father;
    };
    Nodo sx(Nodo n) const {
        return n->sxn;
    };

    Nodo dx(Nodo n) const{
        return n->dxn;
    } ;
    bool sx_empty(Nodo n) const{
        return (n->sxn == NULL);
    };

    bool dx_empty(Nodo n) const{
        return (n->dxn == NULL);
    };

    //virtual void costr(Bin_tree<T,N>);


    void erase(Nodo n){

        while(!sx_empty(n)){
            if(!sx_empty(n)) erase(n->sxn);
        }
        while(!dx_empty(n)){
            if(!dx_empty(n)) erase(n->dxn);
        }

        if(sx_empty(n) && dx_empty(n)){
            delete n;
        }
    };


    T read(Nodo n) const{
        return n->value;
    };

    void write(Nodo n, const value_type &v){
        if(n != NULL)
            n->value = v;
    };

    void ins_root(Nodo n){
        if(_root != NULL){
            throw(" radice già presente");
        }
        _root = new cella<T>;
        _root->father = NULL;
        _root->dxn = NULL;
        _root->sxn = NULL;

    };
    void ins_sx(Nodo n){
        n->sxn = new cella<T>;
    };
    void ins_dx(Nodo n){
        n->dxn = new cella<T>;
    };
};

#endif //TEST_BUILD_ALBERIPUNTATORI_H
