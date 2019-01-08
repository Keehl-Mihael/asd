#include <queue>
#include <math.h>       /* pow */
template< class I>
class richieste{
private:
	typedef typename alberiPuntatori<I>::Nodo node;

    void postvisitaModificato(alberiPuntatori<int> &T,node n,int &c){
        if (n == NULL) {return; }

        postvisitaModificato(T,T.dx(n),c);
        postvisitaModificato(T,T.sx(n),c);
        if(T.leaf(n)){
            if( T.read(n) % 2 ==0){
                c ++;
            }
        }

        //cout << read(n) << endl; // After
    }

public:

	int odd(alberiPuntatori<int> &T,int k){
		std:queue<node> coda;
		node n;
		n = T.root();
		coda.push(n);
		int counter=0,numnodi =0,numnodi2 = pow(2,k-1) - pow(2,k-2);

		while(!coda.empty()){

			node u = coda.front();
			coda.pop();

            if(numnodi >= numnodi2 && numnodi <= pow(2,k)){
				if( T.read(u) % 2 ==1){
					counter ++;
				}
			}
			if(numnodi - 1 < 0){
			    numnodi ++;
			}
            numnodi -= 1;


            if(!T.sx_empty(u)){
				numnodi +=1;
				coda.push(T.sx(u));
			}
			if(!T.dx_empty(u)){
				numnodi +=1;
				coda.push(T.dx(u));
			}

		}
		return counter;

	}

	int even_leafs(alberiPuntatori<int> &T){
        int counter = 0;
        this->postvisitaModificato(T,T.root(),counter);
        return counter;
	}



};