/*
 * Chapter 6
 * Paragraph 1
 *
 * Binary tree data structure implementation
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <string>
template <class T>
class BinaryTree {
public:
  BinaryTree(T, T);

  BinaryTree* lookupNode(T);

  void insertNode(T, T);

  BinaryTree* removeNode(T);

  BinaryTree* min();

  BinaryTree* max();

  BinaryTree* successorNode();

  BinaryTree* predecessorNode();

  void simmetricView(BinaryTree<T>* );

  BinaryTree<T>* root();

  int countNodi(BinaryTree<T>*);

  void changesubtree(BinaryTree<T>* nodo1, BinaryTree<T>* nodo2);

  int lenght();

    int getLevel();
    int getColor();

  ~BinaryTree();

  T key() {return _key;}
  T value() {return _value;}

  BinaryTree* parent;
  BinaryTree* left;
  BinaryTree* right;
  int _num_nodi;
  int index_color;
  int level;

private:
  T _value;
  T _key;

  int _lenght;

  std::string colors[3]= {"red","green","white"};
};

template <class T>
BinaryTree<T>::BinaryTree(T k, T v) : _key(k), _value(v), parent(0), left(0), right(0),
_lenght(0),_num_nodi(0){ }

template <class T>
BinaryTree<T>* BinaryTree<T>::lookupNode(T x) {
  BinaryTree<T>* t = this;
  while (t != 0 && t->key() != x) {
    t = x < t->key() ? t->left : t->right;
  }
  return t;
}

template <class T>
void link(BinaryTree<T>* v, BinaryTree<T>* u, T x) {
  if (u != 0) {
    u->parent = v;
  }

  if (v != 0) {
    if (x < v->key()) {
      v->left = u;
    }
    else {
      v->right = u;
    }
  }
}

template <class T>
void BinaryTree<T>::insertNode(T x, T v)
{
  BinaryTree<T>* s = 0;
  BinaryTree<T>* u = this;
  int level = 0;

  while (u != 0 && u->key() != x) {
    s = u;
    u = x < u->key() ? u->left : u->right;
    level ++;
  }
  if (u != 0 && u->key() == x) {
    u->_value = v;
    u->_num_nodi = countNodi(u);
    u->index_color = u->key() %  3 ;
    u->level = level;
  }
  else {
    BinaryTree<T>* n = new BinaryTree<T>(x, v);
    link(s, n, x);
    n->_num_nodi = countNodi(n);
    n->level = level;

  }
  _lenght ++;
}


template <class T>
BinaryTree<T>* BinaryTree<T>::removeNode(T x) {
  BinaryTree<T>* u = this->lookupNode(x);
  if (u != 0) {
    if (u->left != 0 && u->right != 0) {  // target has 2 children
      BinaryTree<T>* s = u->right;
      while (s->left != 0) {
        s = s->left;
      }

      u->_key = s->key();
      u->_value = s->value();


      x = s->key();

      u = s;
    }

    BinaryTree<T>* t;
    if (u->left != 0 && u->right == 0) {  // has only a left child
      t = u->left;
    }
    else {  // only right child or no children
      t = u->right;
    }

    link(u->parent, t, x);

    _lenght --;


     if (u->parent == 0) {  // u is the root, u==this
      if (t != 0) {
        t->parent = 0;  // t is the new root
      }

      this->left = 0;
      this->right = 0;
      delete this;

      return t;
    }
    else {
      u->parent = 0;
      u->left = 0;
      u->right = 0;
      delete u;
    }

    return this;
  }
}

template <class T>
BinaryTree<T>* BinaryTree<T>::min() {
  BinaryTree<T>* t = this;
  while (t->left != 0) {
    t = t->left;
  }
  return t;
}

template <class T>
BinaryTree<T>* BinaryTree<T>::max() {
  BinaryTree<T>* t = this;
  while (t->right != 0) {
    t = t->right;
  }
  return t;
}

template <class T>
BinaryTree<T>* BinaryTree<T>::successorNode() {
  BinaryTree<T>* t = this;
  if (t->right != 0) {
    return t->right->min();
  }
  BinaryTree<T>* s = t->parent;
  while (s != 0 && t == s->right) {
    t = s;
    s = s->parent;
  }
  return s;
}


template <class T>
BinaryTree<T>* BinaryTree<T>::predecessorNode() {
  BinaryTree<T>* t = this;
  if (t->left != 0) {
    return t->left->max();
  }
  BinaryTree<T>* s = t->parent;
  while (s != 0 && t == s->left) {
    t = s;
    s = s->parent;
  }
  return s;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
  if (this->left != 0) {
    delete this->left;
    this->left = 0;
  }

  if (this->right != 0) {
    delete this->right;
    this->right = 0;
  }
}

template <class T>
void BinaryTree<T>::simmetricView(BinaryTree<T>* x) {

    //cout << "prima di controllo" << x->key() << " " << x->value() << endl;


    if (x->left != 0) {
        //cout << "sinistra" << endl;

        simmetricView(x->left);
    }

    std::cout << x->key() << " " << x->value() << std::endl;

    if (x->right != 0) {
        //cout << "destra"  << endl;

        simmetricView(x->right);
    }
}

template <class T>
int BinaryTree<T>::lenght() {
    return _lenght;
}

template <class T>
BinaryTree<T>* BinaryTree<T>::root() {
    return this;
}

template <class T>
int BinaryTree<T>::countNodi(BinaryTree<T>* nodo){
    int count = 0;
    if(nodo->left == 0 && nodo->right == 0){
        count = 1;
    }else{
        if(nodo->left != 0 ){
            count += countNodi(nodo->left);
        }
        if(nodo->right != 0 ){
            count += countNodi(nodo->right);
        }
    }
    return count;
}

template <class T>
void BinaryTree<T>::changesubtree(BinaryTree<T>* nodo1, BinaryTree<T>* nodo2){
    BinaryTree<T>* temp;

    temp->parent = nodo1->parent;
    temp->left = nodo1->left;
    temp->right = nodo1->right;

    nodo1->parent = nodo2->parent;
    nodo1->right = nodo2->right;
    nodo1->left = nodo2->left;

    nodo2->parent = temp->parent;
    nodo2->left = temp->left;
    nodo2->right = temp->right;
}

template <class T>
int BinaryTree<T>::getLevel(){
    return level;
}
template <class T>
int BinaryTree<T>::getColor(){
    return index_color;
}

#endif
