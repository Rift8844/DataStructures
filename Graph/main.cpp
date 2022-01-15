#include "Point.h"
#include <cassert>
#include <exception>
#include <iostream>

int main() {

	Vertex a, b;

	std::cout << "Hello world of geometry!" << std::endl;

	a.connect(&b);
	assert(a.getDegree() == 1 && b.getDegree() == 1);

	b.disconnect(&a);
	assert(a.getDegree() == 0 && b.getDegree() == 0);


	/*Vertex B should throw an exception if 
	it is not connected to A*/
	bool excThrown = false;

	try {
		b.disconnect(&a);
	} catch (...) {
		excThrown = true;
	}
	assert(excThrown);

	return 0;
}