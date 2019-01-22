//
// Created by siroid on 12/16/18.
//

#ifndef TEST_BUILD_LAB12_H
#define TEST_BUILD_LAB12_H

#include "../codepriority/codaPriorita.h"
#include "../codepriority/appartiene.h"

template<class E, class P, class N>
class lab12 {
public:

    typedef typename Grafo<E, P, N>::ListaNodi ListaNodi;
    typedef typename Grafo<E, P, N>::Nodo Nodo;
    typedef typename Grafo<E, P, N>::ListaNodiPos p;


    static int outDegree(Grafo<E, P, N> &grafo, Nodo n) {
        int count = 0;
        ListaNodi l = grafo.Adiacenti(n);
        p start = l.begin();
        while (!l.end(start)) {
            start = l.next(start);
            count++;
        }
        return count;
    }

    static int inDegree(Grafo<E, P, N> &grafo, Nodo n) {
        int count = 0;
        ListaNodi ad;
        p start2;
        ListaNodi l = grafo.list_nodi();
        p start = l.begin();
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
        p start = l.begin();
        while (!l.end(start)) {
            sum_archi_usc += inDegree(grafo, *(l.read(start)));
            start = l.next(start);
            num_nodi++;
        }
        return sum_archi_usc / num_nodi;
    }

    static bool findPath(Grafo<E, P, N> &grafo, Nodo r, Nodo d) {
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
    }

    static void bfs(Grafo<E, P, N> &grafo,Nodo u){
        Coda c;
        c.incoda(u);
        while(!c.codaVuota()){
            u = c.leggiCoda();
            c.fuoriCoda();
            cout << u << endl; //marcalo visitato
            ListaNodi n;
            n = grafo.Adiacenti(u);
            position p;
            p = n.begin();
            Nodo v;
            while(!n.end(p)){
                v = n.read(p);
                //esamina l'arco
                if(//v non è visitato e v non appartiene a c){
                //c.incoda(v)
                // }
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
            if(//v non è visitato)
            dfs(grafo,v)

        }
    }




};


#endif //TEST_BUILD_LAB12_H
