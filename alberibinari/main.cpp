/*
 * Chapter 6
 * Paragraph 1
 *
 * Binary tree data structure usage
 */


#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#include "binarytree.h"
#include "../code/codavtprof.h"
#include "color_bin_tree.h"



template < typename F>
void visitaPerLivelli(BinaryTree<F>* t){
  Coda<F> C(15);
  BinaryTree<F>* nodoAlbero;
  C.inCoda(t->key());
  while(C.codaVuota() == false){
    F nodo = C.leggiCoda();
    C.fuoriCoda();
    nodoAlbero = t->lookupNode(nodo);
    cout << nodoAlbero->key() <<  " livello: "<< nodoAlbero->getLevel() << "\n"; //inserire eliminazione
    /*    modulo = s->value() % 2;

    if(modulo != 0 && s->left ==0 && s->right ){
        cout << "da cancellare per esercizio 9.1 "<< endl;
    }*/
    if(nodoAlbero->left != 0){
      F val = nodoAlbero->left->key();
      C.inCoda(val);

    }
    if(nodoAlbero->right != 0){
      F val1 = nodoAlbero->right->key();
      C.inCoda(val1);
    }

  }
}

int main() {
  BinaryTree<int>* t = new BinaryTree<int>(4, 40);
  t->insertNode(2, 42);
  t->insertNode(5, 5);
  t->insertNode(2, 20);
  t->insertNode(0, 1);
  t->insertNode(99, 99);
  t->insertNode(3, 30);
  t->insertNode(1, 10);
  t->insertNode(0, 42);
  t->insertNode(-1, 10);
  t->insertNode(7, 5);
  t->insertNode(8, 30);

  BinaryTree<int>* k = new BinaryTree<int>(4, 40);
  k->insertNode(2, 4);
  k->insertNode(5, 7);

  t->changesubtree(t->lookupNode(3),k->lookupNode(2));


  int modulo;

  cout << "Rimuovo nodi 0 e 4" << endl;
  t = t->removeNode(0);
  //t = t->removeNode(4);



  cout << "Ora stampo i nodi dell'albero in ordine: " << endl;
  BinaryTree<int>* s = t->min();
  while(s) {
    cout << "Nodo: " << s->key() << "=" << s->value() << " nodi sotto" << s->countNodi(s) << " colore "<< s->getColor() << " livello " <<s->getLevel()  <<  endl;



    s = s->successorNode();
  }

  cout << "\n numero nodi " << t->lenght() << endl;

  cout << endl;
  cout << "Ora stampo i nodi dell'albero in ordine inverso: " << endl;
  s = t->max();
  while(s) {
    cout << "Nodo: " << s->key() << "=" << s->value()  << " nodi sotto" << s->countNodi(s) << endl;

    s = s->predecessorNode();
  }

  cout << "\n simmetric view \n";

  t->simmetricView(t->root());

  cout << "\n level view \n";

  visitaPerLivelli(t->root());




  color_bin_tree::getNumberofRed<int>(t);

  delete t;
}




