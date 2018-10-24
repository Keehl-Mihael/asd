/***************************************************************************
 *   Copyright (C) 2005 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _CODAVT_
#define _CODAVT_
#include <iostream>
#include <cassert>

using namespace std;

template < class tipoelem > class Coda {
public:
       Coda(int);
       Coda();              
       ~Coda();
       void creaCoda();
       bool codaVuota();
       void fuoriCoda();
       tipoelem leggiCoda();
       void inCoda(tipoelem);
       void inCodaNDup(tipoelem);
       // servizio
       void stampaCoda();
       bool contiene(tipoelem);
private:
        tipoelem *elementi;
        int testa, lung, maxlung;
};

template <class tipoelem> Coda<tipoelem>::Coda(int n){
maxlung = n;
creaCoda();
}

template <class tipoelem> Coda<tipoelem>::Coda(){
maxlung = 100; // coda standard di 100 elementi
creaCoda();
}


template <class tipoelem> Coda<tipoelem>::~Coda(){
delete[] elementi;
}

template <class tipoelem> void Coda<tipoelem>::creaCoda(){
elementi = new tipoelem[maxlung];
testa = 0;
lung = 0;
}

template <class tipoelem> bool Coda<tipoelem>::codaVuota(){
return (lung == 0);
}

template <class tipoelem> tipoelem Coda<tipoelem>::leggiCoda(){
assert (!codaVuota());
return (elementi[testa]);
}

template <class tipoelem> void Coda<tipoelem>::fuoriCoda(){
assert(!codaVuota());
testa = (testa + 1) % maxlung;
lung--;
}

template <class tipoelem> void Coda<tipoelem>::inCoda(tipoelem a){
assert(lung != maxlung);
elementi[(testa+lung) % maxlung] = a;
lung++;
}

template <class tipoelem> void Coda<tipoelem>::stampaCoda(){
// lung è il numero di elementi nella coda
   if (!codaVuota())
   {
      int indice;
      for (int i=0; i<lung;i++)
      {
          indice = (testa + i) % maxlung;    
          cout << elementi[indice] << " ";   
      }
   }
   else 
      cout << "CODA VUOTA";   
}   

template <class tipoelem> bool Coda<tipoelem>::contiene(tipoelem e){
// lung è il numemero di elementi nella coda
bool trovato = false;
if (!codaVuota())
{
   int i=0;
   int indice;
   while (!trovato && i<lung)
   {
      indice = (testa + i) % maxlung;
      if (elementi[indice] == e)
         trovato=true;
      i++;            
   }   
}
return trovato;
}

template <class tipoelem> void Coda<tipoelem>::inCodaNDup(tipoelem a){
assert(lung != maxlung);
if (!contiene(a))
{
   elementi[(testa+lung) % maxlung] = a;
   lung++;
}
}
#endif // _CODAVT_H
