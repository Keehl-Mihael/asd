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
        if(root() != NULL){
            erase(_root);
        }
        //
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


    void erase(Nodo &n){

        if(!dx_empty(n)) erase(n->dxn);
        if(!sx_empty(n)) erase(n->sxn);


        if(sx_empty(n) && dx_empty(n)){
            n = NULL;
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
    void previsit(Nodo n){
        if (n == NULL) return;
        cout << read(n) << endl; // Before
        previsit(dx(n));
        previsit(sx(n));
    }
    void invisit(Nodo n){
        if (n == NULL) return;
        invisit(dx(n));
        cout << read(n) << endl; // Between
        invisit(sx(n));
    }

    void postvisit(Nodo n){
        if (n == NULL) return;
        postvisit(dx(n));
        postvisit(sx(n));
        cout << read(n) << endl; // After
    }
    bool leaf(Nodo n){
        if(dx_empty(n) && sx_empty(n)){
            return true;
        }
        return false;
    }
    void costr(Bin_tree<T,cella<T>*> &t){
        alberiPuntatori<T> newTree;
        Nodo newRoot;
        newTree.ins_root(newRoot);
        newTree.ins_dx(this->root());
        newTree.ins_sx(t.root());
        //trovare modo di assegnare nuovo albero
    }
};

#endif //TEST_BUILD_ALBERIPUNTATORI_H
