#ifndef CURSORLIST_H_INCLUDED
#define CURSORLIST_H_INCLUDED

#define CURSORLIST_SIZE 100

#include "list.h"
#include <iostream>

template <class T>
class CellaCursore {
	typedef T tipoelem;
	typedef template <class T,typename P> cursore;

	public:
		CellaCursore() : successivo(nullptr) {}
		CellaCursore( const tipoelem e ) : elemento(e), successivo(nullptr) {}
		CellaCursore( const tipoelem e, cursore s ) : elemento(e), successivo(s) {}

		tipoelem getElemento() const { return elemento; }
		void setElemento( tipoelem e ) { elemento=e; }

		cursore getSuccessivo() const { return successivo; };
		void setSuccessivo( cursore c ) { successivo=c; }

	private:
		tipoelem elemento;
		cursore successivo;
};

template <class T>
class ListaCursore : public Lista<T,CellaCursore<T>*> {
	typedef T tipoelem;
	typedef CellaCursore<T> cella;
	typedef cella* cursore;

	public:
		ListaCursore();
		ListaCursore(int);
		~ListaCursore();

		//virtual Lista crealista();
		bool listavuota() const;
		tipoelem leggilista( cursore ) const;
		void scrivilista( tipoelem, cursore& );
		cursore& primolista();
		bool finelista( cursore ) const;
		cursore succlista( cursore ) const;
		void inslista( tipoelem, cursore& );
		void canclista( cursore& );


		void printlista() const;

	private:
		cella* spazio;
		cella* inizio;
		cella* listalibera;

		void sposta( cursore&, cursore& );
};


// IMPLEMENTAZIONE

// ListaCursore(int)
template <class T>
ListaCursore<T>::ListaCursore(int dim) {
	spazio = new cella[dim];
	listalibera = spazio;

	for (int i=0; i<dim-1; i++)
		spazio[i].setSuccessivo( &spazio[i+1] );

	spazio[dim-1].setSuccessivo( nullptr );

	inizio = nullptr;
}

// ~ListaCursore()
template <class T>
ListaCursore<T>::~ListaCursore() {
	delete [] spazio;
}

// listavuota()
template <class T>
bool ListaCursore<T>::listavuota() const {
	return inizio==nullptr ? true : false;
}

// leggilista( cursore )
template <class T>
typename ListaCursore<T>::tipoelem
ListaCursore<T>::leggilista( cursore c ) const {
    if (c==nullptr)
		throw "Il cursore non punta ad alcun elemento";

	return c->getElemento();
}

// scrivilista( tipoelem, posizione& )
template <class T>
void ListaCursore<T>::scrivilista( tipoelem e, cursore& c ) {
	if (c==nullptr)
		throw "Impossibile sovrascrivere elemento non esistente";
	c->setElemento(e);
}

// primolista()
template <class T>
typename ListaCursore<T>::cursore&
ListaCursore<T>::primolista() {
	return inizio;
}

// finelista( cursore )
template <class T>
bool ListaCursore<T>::finelista( cursore c ) const {
    return c->getSuccessivo()==nullptr ? true : false;
}

// succlista( cursore )
template <class T>
typename ListaCursore<T>::cursore
ListaCursore<T>::succlista( cursore c ) const {
	return c->getSuccessivo();
}

// inslista( tipoelem,cursore )
template <class T>
void ListaCursore<T>::inslista( tipoelem e, cursore& c ) {
	if ( listalibera == nullptr )
		throw "Spazio disponibile terminato";
	sposta(listalibera, c);
	c->setElemento(e);
}

// canclista( cursore )
template <class T>
void ListaCursore<T>::canclista( cursore& c ) {
	if ( c == nullptr )
		throw "Impossibile eliminare elemento non esistente";
	sposta(c,listalibera);
}

// sposta( cursore&,cursore& )
template <class T>
void ListaCursore<T>::sposta( cursore& h, cursore& k ) {
	cursore temp = k;
	k = h;
	h = h->getSuccessivo();
	k->setSuccessivo(temp);
}



// printlista() const;
template <class T>
void ListaCursore<T>::printlista() const {

    for (cursore c = inizio; c!=nullptr; c=c->getSuccessivo())
		std::cout << c->getElemento() << " ";

}


#endif // CURSORLIST_H_INCLUDED
