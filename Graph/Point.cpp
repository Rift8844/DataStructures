#include <iostream>
#include <exception>
#include "Point.h"

void Vertex::connect(Vertex* const v) {
	conns.insert(v);

	if (v != this)
		v->conns.insert(this);
}

void Vertex::disconnect(Vertex* const v) {

	auto it = conns.find(v);

	if (it == conns.end()) {

		throw std::exception();
	}

	conns.erase(it);
	if (v != this)
		v->conns.erase(this);
}