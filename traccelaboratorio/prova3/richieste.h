template< class T>
class richieste{
public:
	void ordinapila(stack<int> &pila){
		map<int,int> test;
		int elem;
		while(!pila.empty()){
			elem = pila.top();
			pila.pop();
			test[elem] = elem;
		}
		
		for(map<int,int>::iterator it=test.begin(); it!=test.end();++it){	
			//cout << it->first;		
			pila.push(it->first);			
		}
	}
};