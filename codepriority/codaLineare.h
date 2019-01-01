/*
 * codaLineare.h
 *
 *  Created on: 24 ott 2018
 *      Author: utente
 */

#ifndef CODALINEARE_H_
#define CODALINEARE_H_

template <class T , class P>
class codaLineare
{
public:
	typedef T valore;
	typedef P posizione;

	virtual void creaCoda() = 0;
	virtual bool codaVuota()const= 0;
	virtual valore leggiCoda()const = 0;
	virtual void fuoriCoda() = 0;
	virtual void inCoda(const valore&) = 0;
};

#endif /* CODALINEARE_H_ */
