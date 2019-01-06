//
// Created by arcangelo on 02/01/19.
//



#include <iostream>
using namespace std;
#include "../../alberi/treelink/TreeLink.h"
#include "richieste.h"

int main(){
    richieste rich;
    TreeLink<int> tree;

    tree.insRoot(1);

    tree.insFirst(tree.root(), 2);
    tree.insFirst(tree.root(), 3);
    tree.ins(tree.firstChild(tree.root()),4);


    tree.insFirst(tree.firstChild(tree.root()), 5);
    tree.insFirst(tree.firstChild(tree.root()), 6);

    cout << rich.maxLevelSum(tree);
    return 0;
}