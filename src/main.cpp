//============================================================================
// Name        : 676319_ultimo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "histogram.h"

int main() {
	histogram hist;
	hist.add(1);
	hist.add(1);
	hist.add(1);
	hist.add(1);
	hist.add(2);
	hist.add(2);
	hist.add(1);
	hist.remove(1);
	
	cout << "MODE: " << hist.mode() << endl;
	cout << "MEAN: " << hist.mean() << endl;
	cout << "HISTOGRAM" << endl;
	hist.print();

	return 0;
}
