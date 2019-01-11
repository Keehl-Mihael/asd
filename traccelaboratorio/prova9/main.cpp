//
// Created by siroid on 1/1/19.
//

#include <iostream>
using namespace std;
#include <list>
#include <map>
#include "richieste.h"

int main(){

    list<string> l;

    recommender r;
    r.insert("u1","p1",1);
    r.insert("u1","p3",3);
    r.insert("u1","p5",4);
    r.insert("u2","p1",2);
    r.insert("u2","p2",3);
    r.insert("u2","p3",3);
    r.insert("u3","p1",1);
    r.insert("u3","p2",1);
    r.insert("u3","p3",1);
    r.insert("u3","p5",5);
    r.insert("u4","p3",2);
    r.insert("u4","p4",4);
    r.insert("u5","p2",3);
    r.insert("u5","p3",2);
    r.insert("u6","p4",2);

    cout << r.meanUser("u3") << endl;
    cout << r.meanItem("p1") << endl;

    l= r.rated("u3");
    list<string>::iterator it;
    for(it=l.begin();it != l.end(); ++it){
        cout << *it << endl;
    }

    cout << "common products" << endl;

    l= r.common("u5","u2");

    for(it=l.begin();it != l.end(); ++it){
        cout << *it << endl;
    }





    return 0;
}