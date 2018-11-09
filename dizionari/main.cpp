#include <iostream>

using namespace std;

#include "hash_table.h"



int main() {
  HashTable<string,string> t(10);
  cout << " size " << t.size() << endl;
  struct Entry<string,string> e1;
  string test = "giovannewi";

  e1.first="rossi";
  e1.second="giovanni";
  t.insert(e1);
  cout << t.find("rossi")->second << endl;

  struct Entry<string,string> e2;
  e2.first="rossi";
  e2.second="marco";
  t.insert(e2);
  cout << t.find("rossi")->second << endl;

  cout << t.lookfor(test);

  return 0;
}
