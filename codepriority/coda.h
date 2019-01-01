/*
 * coda.h
 *
 *  Created on: 24 ott 2018
 *      Author: utente
 */
#ifndef CODA_H_
#define CODA_H_

#include "codaLineare.h"
#include <iostream>

template <class T>
class Coda;

template <class T>
class Nodo
{
public:
	friend class Coda<T>;
private:
	T valore;
	Nodo<T> *succ;
};

template <class T>
class Coda : public codaLineare<T , Nodo<T>*>
{
public:
	typedef typename codaLineare<T , Nodo<T>*>::valore valore;
	typedef typename codaLineare<T , Nodo<T>*>::posizione posizione;

	Coda();
	~Coda();
	Coda(Coda<T>&);
	Coda<T>& operator=(Coda<T>&);
	bool operator==(const Coda<T>&);
	void creaCoda();
	bool codaVuota()const;
	valore leggiCoda()const;
	posizione CodaRefer()const;
	void fuoriCoda();
	void inCoda(const valore&);
	void stampaCoda();
	int getSize(){return numNodi;}
private:
	Nodo<T> *testa;
	Nodo<T> *coda;
	int numNodi;
};

template <class T>
Coda<T>::Coda()
{
	testa = new Nodo<T>;
	coda = new Nodo<T>;
	testa->succ = testa;
	coda->succ = coda;
	numNodi = 0;
}

template <class T>
Coda<T>::~Coda()
{
	while(!codaVuota())
		fuoriCoda();
	delete testa;
	delete coda;
}

template <class T>
Coda<T>::Coda(Coda<T> &C)
{
	this->numNodi = C.numNodi;

	this->testa = new Nodo<T>;
	this->coda = new Nodo<T>;

	testa->succ = testa;
	coda->succ = coda;

	for(int i=0;i<C.getSize();i++)
	{
		valore elemento = C.leggiCoda();
		this->inCoda(elemento);
		C.fuoriCoda();
		C.inCoda(elemento);
	}
}
/*
template <class T>
Coda<T>& Coda<T>::operator =(Coda<T> &C)
{
	;
}

template <class T>
bool Coda<T>::operator ==(const Coda<T> &C)
{
	;
}
*/
template <class T>
void Coda<T>::creaCoda()
{
	numNodi = 0;
}

template <class T>
bool Coda<T>::codaVuota()const
{
	return (this->numNodi == 0);
}

template <class T>
typename Coda<T>::valore Coda<T>::leggiCoda()const
{
	if(!this->codaVuota())
	   return testa->succ->valore;
	else
		std::cout << "Coda vuota" << std::endl;
}

template <class T>
typename Coda<T>::posizione Coda<T>::CodaRefer()const
{
	if(!this->codaVuota())
	   return testa->succ;
	else
		std::cout << "Coda vuota" << std::endl;
}

template <class T>
void Coda<T>::fuoriCoda()
{
	posizione temp = new Nodo<T>;
	if(!this->codaVuota())
	{
		temp->succ = testa->succ->succ;
		delete testa->succ;
		testa->succ = temp->succ;
		numNodi--;

	}
	else
		std::cout << "Coda vuota" << std::endl;
}

template <class T>
void Coda<T>::inCoda(const valore &V)
{
	posizione nodo = new Nodo<T>;
	nodo->valore = V;

	if(this->codaVuota())
	{
		testa->succ = nodo;
		nodo->succ = nullptr;
		coda->succ = nodo;
	}
	else
	{
		coda->succ->succ = nodo;
		coda->succ = nodo;
		nodo->succ = nullptr;

	}
	numNodi++;

}
#endif /* CODA_H_ */

