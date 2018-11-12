#include <iostream>

using namespace std;

#include "hash_table.h"



int main() {
  HashTable<string,string> t(10);
  cout << " size " << t.size() << endl;
  struct Entry<string,string> e1;
  string test = "giovannewi";

  e1.first="grigio";
  e1.second="giovanni";
  t.insert(e1);
  cout << t.find("grigio")->second << endl;

  struct Entry<string,string> e2;
  e2.first="rossi";
  e2.second="marco";
  t.insert(e2);
  cout << t.find("rossi")->second << endl;

  cout << t.lookfor(test) << endl;

  cout << "values"  << endl;

  string *val = t.values();
  for(int i=0; i < 10 ; i++){
    if(!val[i].empty()){
      cout<< i << ": "<< val[i] << endl;
    }
  }


  cout << "keys"  << endl;

  val = t.keys();
  for(int i=0; i < 10 ; i++){
    if(!val[i].empty()){
      cout<< i << ": "<< val[i] << endl;
    }
  }


  return 0;
}
