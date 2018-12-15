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
    cella<T> * sx;
    cella<T> * dx;
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
/*        while(!this.empty()){
            erase()
        }*/
        delete _root;
    };
    void create(){
        lenght = 0;
    };
    bool empty() const{
        if(root()!= NULL) return false;
        return true;
    };


    Nodo root() const{
        return this->_root;
    };
    Nodo parent(Nodo n) const{
        return n->father;
    };
    Nodo sx(Nodo n) const {
        return n->sx;
    };

    Nodo dx(Nodo n) const{
        return n->dx;
    } ;
    bool sx_empty(Nodo n) const{
        return (n->sx == NULL);
    };

    bool dx_empty(Nodo n) const{
        return (n->dx == NULL);
    };

    //virtual void costr(Bin_tree<T,N>);
    void erase(Nodo n){
        while(!sx_empty(n) || !dx_empty(n)){
            if(!sx_empty(n)) erase(n->sx());
            if(!dx_empty(n)) erase(n->dx());
        }
        //erase(n);
    };


    T read(Nodo n) const{
        return n->value;
    };

    void write(Nodo n, value_type v){
        if(this->_root == _root){ //nodo appartiene ad albero
            n->value = v;
        }
    };

    void ins_root(Nodo n){
        if(_root != NULL){
            throw(" radice già presente");
        }
        _root = n;
        write(_root,read(n));
        _root->dx = n->dx;
        _root->sx = n->sx;
    };
    void ins_sx(Nodo n){
        //this->sx = n;
    };
    void ins_dx(Nodo n){
        //this->dx = n;
    };
};

#endif //TEST_BUILD_ALBERIPUNTATORI_H
