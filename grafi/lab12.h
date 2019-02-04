//
// Created by siroid on 12/16/18.
//

#ifndef TEST_BUILD_LAB12_H
#define TEST_BUILD_LAB12_H

#include "../codepriority/codaPriorita.h"
#include "../codepriority/appartiene.h"
#include <map>
#include <queue>

template<class E, class P, class N>
class lab12 {
public:

    typedef typename Grafo<E, P, N>::ListaNodi ListaNodi;
    typedef typename Grafo<E, P, N>::Nodo Nodo;
    typedef typename Grafo<E, P, N>::ListaNodiPos position;


    static int outDegree(Grafo<E, P, N> &grafo, Nodo n) {
        int count = 0;

        ListaNodi l = grafo.Adiacenti(n);
        position start = l.begin();
        while (!l.end(start)) {
            start = l.next(start);
            count++;
        }
        return count;
    }

    static int inDegree(Grafo<E, P, N> &grafo, Nodo n) {
        int count = 0;
        ListaNodi ad;
        position start2;
        ListaNodi l = grafo.list_nodi();
        position start = l.begin();
        while (!l.end(start)) {
            ad = grafo.Adiacenti(start);
            start2 = ad.begin();
            while (!ad.end(start2)) {
                if (n.getId() == (ad.read(start2))->getId()) {
                    count++;
                }
                start2 = ad.next(start2);
            }
            start = l.next(start);
        }
        return count;
    }

    static double meanOutDegree(Grafo<E, P, N> &grafo) {
        ListaNodi l = grafo.list_nodi();
        int num_nodi = 0, sum_archi_usc = 0;
        position start = l.begin();
        while (!l.end(start)) {
            sum_archi_usc += inDegree(grafo, *(l.read(start)));
            start = l.next(start);
            num_nodi++;
        }
        return sum_archi_usc / num_nodi;
    }

  /*  static bool findPath(Grafo<E, P, N> &grafo, Nodo r, Nodo d) {
        int n = grafo.numNodi();
        CodaPriorita<E> c;
        appartiene<int> app;

        int T[n], DIST[n];
        int k,i,x;
        for (k = 0; k < n; k++) {
            if (k != r) {
                T[k] = r;
                DIST[k] = 100;
            }
            c.inserisciMin(r.etichetta);
            while(c.min() != NULL){
                i = c.min();
                c.deleteMin();
                ListaNodi Lj = grafo.Adiacenti(i);
                int m = 0;
                while(x = Lj.next(m) != NULL){
                    if(DIST[i] + x->peso < DIST[x] ){
                        T[x] = i;
                        DIST[x] = DIST[i] + x->peso;
                        if(!app.appart(c,x)){
                            c.inserisciMin(x);
                        }
                    }
                    m++;
                }
            }
        }
        return false;
    }*/

    static void bfs(Grafo<E, P, N> &grafo,Nodo u){
      std::queue<Nodo> c;
      std::queue<Nodo> temp;
      std::map<Nodo,bool> visited;
        bool flag=0;
        c.push(u);
        while(!c.empty()){
            u = c.front();
            c.pop();
            cout << grafo.leggiEtichetta(u) << endl; //marcalo visitato
            visited[u] = true;
            ListaNodi n;
            n = grafo.Adiacenti(u);
            position p;
            p = n.begin();
            Nodo *v;
            while(!n.end(p)){
                v = n.read(p);
                cout << v << endl;
                visited[*v] = true;
                flag = false;
                /*while(!c.empty()) // q1 is your initial queue.
                {
                    int u = c.front();

                    // do what you need to do with this value.

                    q1.pop();
                    tem.push(u);
                }


                while(!tem.empty())
                {
                    int u = tem.front();
                    tem.pop();
                    q1.push(u); // putting it back in our original queue.
                }*/
                for(auto i=c.begin();i!=c.end();++i){
                    if(grafo.leggiEtichetta(*i) == grafo.leggiEtichetta(v)){ flag = true;}
                }
                //esamina l'arco
                if(!visited[*v] && flag){
                    c.push(v);
                 }
                p = n.next(p);
            }
        }
    }

    static void dfs(Grafo<E, P, N> &grafo,Nodo u){
        cout << u << endl; //marcalo visitato
        ListaNodi n;
        n = grafo.Adiacenti(u);
        position p;
        p = n.begin();
        Nodo v;
        while(!n.end(p)){
            v = n.read(p);
            //esamina l'arco e marcalo visitato
            //if(//v non è visitato)
            //dfs(grafo,v);

        }
    }






};


#endif //TEST_BUILD_LAB12_H
