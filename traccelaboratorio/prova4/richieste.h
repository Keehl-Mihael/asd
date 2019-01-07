#include <queue>
template< class I>
class richieste{
private:
	typedef typename alberiPuntatori<I>::Nodo node;


public:
/*	void multipli(alberiPuntatori<int> &T){
		this->invisitaModificato(T,T.root());

	}*/

	void visitaPerLivelli(alberiPuntatori<int> &T){
		std:queue<node> coda;
		node n;
		n = T.root();
		coda.push(n);

		while(!coda.empty()){

			node u = coda.front();
			coda.pop();
			cout << T.read(u) << endl;
			if(!T.sx_empty(u)){
				coda.push(T.sx(u));
			}
			if(!T.dx_empty(u)){
				coda.push(T.dx(u));
			}
		}

	}
};