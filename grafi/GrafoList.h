#ifndef GRAFOLIST_H
#define GRAFOLIST_H

#include "Grafo.h"
#include "list_vector.h"

class NodoG{
  public:
    NodoG(int i){
      nodoId = i;
    }
    NodoG(){
    }
    int getId(){ return nodoId; }
    void setId(int id) {nodoId = id;}
  private:
    int nodoId;
};


template<class P>
class InfoArco {
  public:
    P peso;
    NodoG _to;
};


template<class E, class P>
class InfoNodo {
  public:
    E   etichetta;
    bool vuoto;
    List_vector<InfoArco<P>> archi;

    InfoNodo(){
      vuoto = true;
    }

    ~InfoNodo(){
	  }
};



template<class E, class P>
  class GrafoList : public Grafo<E, P, NodoG > {
 public:
    typedef E Etichetta;
    typedef P Peso;
    typedef NodoG Nodo;
    typedef Arco_<Peso, Nodo> Arco;
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
    typedef typename Grafo_::ListaNodi ListaNodi;
    typedef typename Grafo_::ListaNodiPos ListaNodiPos;

    GrafoList(int);
    ~GrafoList();

    bool vuoto() const;
    void insNodo(NodoG&);
    void insArco(Nodo, Nodo, Peso);
    void cancNodo(Nodo);
    void cancArco(Nodo, Nodo);
    bool esisteNodo(Nodo);
    bool esisteArco(Arco);
    ListaNodi Adiacenti(Nodo) const ;
    ListaNodi list_nodi() const ;
    Etichetta leggiEtichetta(Nodo) const ;
    void scriviEtichetta(Nodo, Etichetta) ;
    Peso leggiPeso(Nodo, Nodo) const ;
    void scriviPeso(Nodo, Nodo, Peso) ;

    int numNodi(){
      return nodi;
    };
    int numArchi(){
      return archi;
    };


 private:
    InfoNodo<E,P>* matrice;
    int dimensione;
    int nodi;
    int archi;
};


template<class E, class P>
GrafoList<E, P>::GrafoList(int _dimensione){
  dimensione = _dimensione;
  nodi = 0;
  archi = 0;
  matrice = new InfoNodo<E,P>[dimensione];
  for (int i=0; i<dimensione; i++)
    matrice[i].archi.create();
}

template<class E, class P>
GrafoList<E, P>::~GrafoList() {
  delete [] matrice;
}

template<class E, class P>
bool GrafoList<E, P>::vuoto() const {
  return (nodi == 0);
}

template<class E, class P>
void GrafoList<E, P>::insNodo(Nodo& N) {
  int n = 0;
  if (nodi < dimensione){
    while (matrice[n].vuoto == false)
      n++;
    nodi++;
    matrice[n].vuoto = false;
  }
  N.setId(n);
}

template<class E, class P>
void GrafoList<E, P>::insArco(Nodo n1, Nodo n2, P peso) {
  InfoArco<P> I;
  I.peso = peso;
  I._to = n2;
  matrice[n1.getId()].archi.insert(I, matrice[n1.getId()].archi.begin());
  archi++;
}


template<class E, class P>
void GrafoList<E, P>::cancNodo(Nodo n) {
  // ATTENZIONE: controllare prima che non ci siano archi uscenti o entranti in n
  bool canc = true;
  int i;
  for (i=0; i < dimensione && canc; i++)
    if (!matrice[n.getId()].archi.empty())
      canc = false;
  // TODO: implementare il controllo sugli archi entranti

  if (canc){
    // la lista  matrice[n.getId()].archi è vuota;
    matrice[n.getId()].vuoto = true;

  }
}

template<class E, class P>
void GrafoList<E, P>::cancArco(Nodo n1, Nodo n2){
	typename List_vector<InfoArco<P>>::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else
				p = matrice[n1.getId()].archi.next(p);
	}
	if (trovato)
		matrice[n1.getId()].archi.erase(p);
  archi--;
}

template<class E, class P>
typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::Adiacenti(Nodo n) const{
  ListaNodi list;
  typename List_vector<InfoArco<P>>::position p;
	p = matrice[n.getId()].archi.begin();
  while (!matrice[n.getId()].archi.end(p)){
		list.insert(new NodoG(matrice[n.getId()].archi.read(p)._to), list.begin());
	  p = matrice[n.getId()].archi.next(p);
	}
  return list;

}

template<class E, class P>
typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::list_nodi() const {
  ListaNodi list;
  for (int i = 0; i < dimensione; i++)
    if (!matrice[i].vuoto)
      list.insert(new NodoG(i), list.begin());
  return list;
}

template<class E, class P>
E GrafoList<E, P>::leggiEtichetta(Nodo n) const {
  return matrice[n.getId()].etichetta;
}

template<class E, class P>
void GrafoList<E, P>::scriviEtichetta(Nodo n, E etichetta) {
  matrice[n.getId()].etichetta = etichetta;
}

template<class E, class P>
P GrafoList<E, P>::leggiPeso(Nodo n1, Nodo n2) const {
	typename List_vector<InfoArco<P> >::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else
				p = matrice[n1.getId()].archi.next(p);
	}
	if (trovato)
		return matrice[n1.getId()].archi.read(p).peso;
}

template<class E, class P>
void GrafoList<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) {
	typename List_vector<InfoArco<P> >::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else
				p = matrice[n1.getId()].archi.next(p);
	}
	if (trovato){
		InfoArco<P> I;
		I.peso = peso;
		I._to = n2;
		matrice[n1.getId()].archi.write(I,p);
	}
}




template<class E, class P>
bool GrafoList<E, P>::esisteArco(Arco a1){
    Nodo n1 = a1.nodo1,n2 = a1.nodo2;
    typename List_vector<InfoArco<P>>::position p;
    p = matrice[n1.getId()].archi.begin();
    while (!matrice[n1.getId()].archi.end(p)){
        if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
            return true;
        else
            p = matrice[n1.getId()].archi.next(p);
    }
    return false;
}

template<class E, class P>
bool GrafoList<E, P>::esisteNodo(Nodo n) {
    // ATTENZIONE: controllare prima che non ci siano archi uscenti o entranti in n
    int i;
    for (i=0; i < dimensione; i++)
        if (!matrice[n.getId()].archi.empty())
            return true;
    // TODO: implementare il controllo sugli archi entranti

    return false;
}
template<class E, class P>
void GrafoList<E, P>::topologicalSortUtil(Nodo v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited

    visited[v.getId()] = true;


    // Recur for all the vertices adjacent to this vertex
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }

    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}

 template<class E, class P>
 void GrafoList<E,P>::shortestPath(Nodo s){
     int V =10;
    stack<int> Stack;
    int dist[V]; //v num nodi
 // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Initialize distances to all vertices as infinite and distance
    // to source as 0
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[s] = 0;

    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        Nodo u = Stack.top();
        Stack.pop();

        // Update distances of all adjacent vertices
        ListaNodi adj = Adiacenti(u);
        typename List_vector<InfoArco<P>>::position p;
        p = adj.begin();

        if (dist[u] != INF)
        {
            while (!adj.end(p)){

                if (dist[i->getV()] > dist[u] + i->getWeight())
                    dist[i->getV()] = dist[u] + i->getWeight();
                p = adj.next(p);
            }


        }
    }

    // Print the calculated shortest distances
    for (int i = 0; i < V; i++)
        (dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";
}



#endif
