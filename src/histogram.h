/*
 * histogram.h
 *
 *  Created on: 15 gen 2019
 *      Author: studente
 */

#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

#include "hash_table.h"


class histogram {
public:
	histogram();
	virtual ~histogram();
	virtual void add (int v);
	virtual void remove(int v);
	virtual int mode();
	virtual double mean();
	virtual void print();
private:

	 HashTable<int,int> isto;


};

histogram::histogram() :isto(10) {
	 //HashTable<int,int> isto(10);

}

histogram::~histogram() {

}


void histogram::add (int v){
	Entry< int, int>* b = isto.find(v);
	    // chack if matching element found
	    if (b != NULL){
	    	isto.modify(v,b->second+1); //non incremetare second ma passare come parametro b->second+1
	    } else {
	    	Entry< int, int> newentry;
	    	newentry.first = v;
	    	newentry.second =  1; //ERROR: al primo inserimento deve essere 1 non 0
	       isto.insert(newentry);
	    }
};
void histogram::remove(int v){
	Entry< int, int>* b = isto.find(v);
	    // chack if matching element found 
	    if (b != NULL){
	    	isto.modify(v,b->second-1); //ERROR: non deve decrementare second
	    }
};
int histogram::mode(){
	 int *keys = isto.keys();
	 int max = 0;
	 int key=0;
	  for(int i=0; i <= isto.size() ; i++){ //ERROR: non < ma <=
		  Entry< int, int>* b = isto.find(keys[i]); //ERROR: check va fatto ciclando sulle chiavi e non sui valori, l'ordine dei valori può non rispettare l'ordine della chiavi
	       if(b!=NULL && b->second > max){
	    	   max = b->second;
	    	   key=keys[i];
	       }

	  }
	return key;

};
double histogram::mean(){
	 int *val = isto.values();
	 int sum = 0;
	  for(int i=0; i <= isto.size() ; i++){ //ERROR: non < ma <=
	    	   sum += val[i];

	  }
	return sum/isto.size();
};
void histogram::print(){
	 int *val = isto.keys();
	  for(int i=0; i <= isto.size() ; i++){ //ERROR; non < ma <=
	    	  std::cout << val[i] << " ";
	    	  Entry< int, int>* b = isto.find(val[i]);
	    	  if (b!=NULL) {
	    	  for(int j=0; j < b->second;j++){
	    		  std::cout << "*";
	    	  }
	    	  
		  }
		  std::cout << std::endl;

	  }
};

#endif /* HISTOGRAM_H_ */
