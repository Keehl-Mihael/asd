#include <iostream>
#include<map>	
#include<stack>
using namespace std;
#include "richieste.h"

int main(){
	
	
	stack<int>   pila;
	richieste<int> rich;
	
	pila.push(1);
	pila.push(3);
	pila.push(2);
	pila.push(5);
	pila.push(7);
	pila.push(4);

	rich.ordinapila(pila);
	
	while(!pila.empty()){
		cout << pila.top() << endl;
		pila.pop();
	}	
	
	return 0;
}