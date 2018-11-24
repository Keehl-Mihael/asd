/*
 * Chapter 6
 * Paragraph 1
 *
 * Binary tree data structure usage
 */


#include <iostream>
using namespace std;
#include "binarytree.h"

#include "../code/codePointer.h"


template < typename F>
void visitaPerLivelli(BinaryTree<F>* t){

  codePointer<F> C;
  C.incoda(t->key());
  while(!C.codavuota()){ //todo chiedere a professore perchè t left va a null dopo codavuota
    F nodo = C.leggicoda();
    C.fuoricoda();
    BinaryTree<F>*  nodoAlbero = t->lookupNode(nodo);
    cout << nodoAlbero->key() << "\n";
    if(nodoAlbero->left != 0){
      F val = nodoAlbero->left->key();
      C.incoda(val);
    }
    if(nodoAlbero->right != 0){
      F val1 = nodoAlbero->right->key();
      C.incoda(val1);
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


/*  int modulo;

  cout << "Rimuovo nodi 0 e 4" << endl;
  t = t->removeNode(0);
  //t = t->removeNode(4);



  cout << "Ora stampo i nodi dell'albero in ordine: " << endl;
  BinaryTree<int>* s = t->min();
  while(s) {
    cout << "Nodo: " << s->key() << "=" << s->value() << endl;

    modulo = s->value() % 2;

    if(modulo != 0 && s->left ==0 && s->right ){
        cout << "da cancellare "<< endl;
    }

    s = s->successorNode();
  }

  cout << "nodi " << t->lenght() << endl;

  cout << endl;
  cout << "Ora stampo i nodi dell'albero in ordine inverso: " << endl;
  s = t->max();
  while(s) {
    cout << "Nodo: " << s->key() << "=" << s->value() << endl;
    s = s->predecessorNode();
  }*/

  //t->simmetricView(t->root());

  visitaPerLivelli(t->root());


  delete t;
}




