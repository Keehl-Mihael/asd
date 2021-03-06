//
// Created by siroid on 11/25/18.
//

#ifndef TEST_BUILD_COLOR_BIN_TREE_H
#define TEST_BUILD_COLOR_BIN_TREE_H

#include <iostream>
#include "../alberibinariricerca/binarytree.h"
#include "../code/codavtprof.h"

using namespace std;

class color_bin_tree {
private:
    typedef int Nodo;

public:
    template <class T>
    static int getNumberofRed(BinaryTree<T>*);
    template <class T>
    static int getNumberofGreenLeafs(BinaryTree<T>*);
    template <class T>
    static void countNodi(BinaryTree<int>* &t,Nodo nodo);

};


template <class T>
int color_bin_tree::getNumberofRed(BinaryTree<T> * BT) {
    Coda<T> C(BT->lenght());
    BinaryTree<T>* nodoAlbero;
    BinaryTree<T>* t;
    std::cout << "\n get number of red \n";
    t = BT->root();
    C.inCoda(t->key());
    int start_level = 0,current_level,pari_o_dispari,max=0,has_red=0,first_max = 0,position=0,count=0;
    while(C.codaVuota() == false){
        T nodo = C.leggiCoda();
        C.fuoriCoda();
        nodoAlbero = t->lookupNode(nodo);
       // cout << nodoAlbero->key() << " value:" << nodoAlbero->value()  <<  " livello: "<< nodoAlbero->getLevel() << " color:" << nodoAlbero->getColor()<< "\n"; //inserire eliminazione

        current_level = nodoAlbero->getLevel();
        pari_o_dispari = (current_level % 2  == 0) ? 1 : 0;

        if(start_level != current_level){
            if(has_red == 0){
                max = 0;
            }
            if(has_red == 1){
                if(first_max < max){
                    first_max = max;
                    position = start_level;
                }

            }
            start_level = current_level;
            has_red = 0;

        }

        if(pari_o_dispari == 1){
            if(nodoAlbero->getColor() == 0){
                if(nodoAlbero->left != 0) {
                    if (nodoAlbero->left->getColor() == 2) {
                        has_red = 1;
                        count ++;

                    }
                }
                if(nodoAlbero->right != 0) {
                    if (nodoAlbero->right->getColor() == 2) {
                        has_red = 1;

                    }
                }
            }
            max += nodoAlbero->value();
        }



        if(nodoAlbero->left != 0){
            T val = nodoAlbero->left->key();
            C.inCoda(val);

        }
        if(nodoAlbero->right != 0){
            T val1 = nodoAlbero->right->key();
            C.inCoda(val1);
        }


    }

/*    if(count){
        std::cout << "Level of max red valore " << first_max <<  " livello: "<< position << "\n"; //inserire eliminazione

    } else
    {
        std::cout << "Nessun nodo rosso ha figlio bianco";
    }*/

    return count;


}


template < class T>
int  color_bin_tree::getNumberofGreenLeafs(BinaryTree<T>* t){
    BinaryTree<T>* s;
    s = t->max();
    int count =0;
    while(s) {

        if(s->left == 0 && s->right == 0 && s->getColor() == 1){
            count++;
        }
        s = s->predecessorNode();
    }
    return count;
}

template <class T>
void color_bin_tree::countNodi(BinaryTree<int>* &t,Nodo nodo){
    int sommasin,sommades;
    if(t->sx_empty(nodo) && t->dx_empty(nodo)){
        t->write(nodo,1)
    }else{
        if(!t->sx_empty(nodo)){
            countNodi(t,t->sx(nodo));
            sommasin = t->read(t->sx(nodo));
        }else{
            sommasin = 0;
            if(!t->dx_empty(nodo)){
                countNodi(t,t->dx(nodo));
                sommades = t->read(t->dx(nodo));
            }else{
                sommades = 0;
                t->write(nodo,sommades+sommasin+1);
            }

        }

    }
}
#endif //TEST_BUILD_COLOR_BIN_TREE_H
