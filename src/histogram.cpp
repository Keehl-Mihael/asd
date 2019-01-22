/*
 * histogram.cpp
 *
 *  Created on: 15 gen 2019
 *      Author: studente
 */

#include "histogram.h"
#include "hash_table.h"

histogram::histogram() {
	 //HashTable<int,int> isto(10);

}

histogram::~histogram() {

}


void histogram::add (int v){
	Entry< int, int>* b = isto.find(v);
	    // chack if matching element found
	    if (b != NULL){
	    	isto.modify(v,b->second++);
	    } else {
	    	Entry< int, int> newentry;
	    	newentry.first = v;
	    	newentry.second =  0;
	       isto.insert(newentry);
	    }
};
void histogram::remove(int v){
	Entry< int, int>* b = isto.find(v);
	    // chack if matching element found
	    if (b != NULL){
	    	isto.modify(v,b->second--);
	    }
};
int histogram::mode(){
	 int *val = isto.values();
	 int max = 0;
	  for(int i=0; i < isto.size() ; i++){
	       if(val[i] > max){
	    	   max = val[i];
	       }

	  }
	return max;

};
double histogram::mean(){
	 int *val = isto.values();
	 int sum = 0;
	  for(int i=0; i < isto.size() ; i++){
	    	   sum += val[i];

	  }
	return sum/isto.size();
};
void histogram::print(){
	 int *val = isto.keys();

	  for(int i=0; i < isto.size() ; i++){
	    	  std::cout << val[i] << " ";
	    	  Entry< int, int>* b = isto.find(val[i]);
	    	  for(int j=0; j < b->second;j++){
	    		  std::cout << "*";
	    	  }
	    	  std::cout << std::endl;

	  }
};
