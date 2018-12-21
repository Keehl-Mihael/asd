//
// Created by arcangelo on 19/12/18.
//

#ifndef TEST_BUILD_GRAFOCONHASHMAP_H
#define TEST_BUILD_GRAFOCONHASHMAP_H

#include <map>
#include <list>

using namespace std;


template <class T>
class grafo;

template <class T>
class arco{
public:
    friend class grafo<T>;
    bool operator==(const arco& a){
        return (a.nodo == this->nodo && a.peso == this->peso);
    }

private:
    T nodo;
    double peso;
};

template <class T>
class grafo{
public:
    grafo(){
        crea();
    }

    void crea(){
        //nudd
    }

    bool vuoto(){
        return grafoInterno.empty();
    }

    void insnodo(T value){
        if(grafoInterno.count(value) == 0){
            list<arco<T>> listaAdiacenza;
            //valore nodo chiave
            //listaAdicenza valore
            grafoInterno[value] = listaAdiacenza;
        }
    }

    void insarco(T nodo_start , T nodo_end,double peso){
        if(grafoInterno.count(nodo_start) == 1 && grafoInterno.count(nodo_end) == 1 ){
            arco<T> arco1;
            arco1.nodo = nodo_end;
            arco1.peso = peso;
            if(find(grafoInterno[nodo_start].begin(),grafoInterno[nodo_start].end(),arco1) == grafoInterno[nodo_start].end()){
                grafoInterno[nodo_start].push_back(arco1);
            }
        }
    }

    void cancnodo(T value){
        for(auto it=grafoInterno.begin(); it != grafoInterno.end(); ++it){
            list<arco<T>> listaAdiacenza = it->second;
            //cout << "nodo in esame " << it->first << " " << endl;
            for(auto el=listaAdiacenza.begin();el != listaAdiacenza.end(); ++el){
                if(el->nodo = value){
                    listaAdiacenza.erase(el);
                }
                //cout << el->nodo << " peso:" << el->peso << '\t';
            }
            //cout << endl;
        }
        grafoInterno.erase(value);
    }

    void cancarco(T nodo_start , T nodo_end,double peso){
        arco<T> arco1;
        arco1.nodo = nodo_end;
        arco1.peso = peso;
        if(find(grafoInterno[nodo_start].begin(),grafoInterno[nodo_start].end(),arco1) != grafoInterno[nodo_start].end()){
            grafoInterno[nodo_start].remove(arco1);
        }
    }

private:
    map<T,list<arco<T>>> grafoInterno;

};

#endif //TEST_BUILD_GRAFOCONHASHMAP_H
