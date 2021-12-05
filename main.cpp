#include "avl_tree_impl.hpp"
#include "prettyprinter.hpp"
#include <time.h>
#include <iostream>
#include <array>


template<typename T> std::ostream& operator<<(std::ostream& os, Node<T>* node) {
	return os << "------\nValue: " << std::dec << node->elem <<
	"\nParent address: " << std::hex << reinterpret_cast<uint16_t> (node->parent)
	<< "\nSon address: " << std::hex << reinterpret_cast<uint16_t> (node->son) <<
	"\nDaughter address: " << std::hex << reinterpret_cast<uint16_t> (node->daughter) << 
	"\n------" << std::endl;

}

void checkTree(Node<int>* node) {

	if (node->hasSon()) {
		checkTree(node->son);

		if (node->son->parent != node)
			throw std::exception();
	}

	if (node->hasDaughter()) {
		checkTree(node->daughter);

		if (node->daughter->parent != node)
			throw std::exception();
	}
}

int main() {

	AvlTree<int> tree;

	uint64_t systime = time(NULL);
	//std::cout << systime << std::endl;

	srand(systime);

	//std::cout << systime << std::endl;

	std::array<int, 20> list;
	std::cout << "Number test suite: \n";

	for (int i = 0; i < 20; i++) {
		int x = rand() % 100;
		std::cout << x << std::endl;
		list[i] = x;
	}


	for (auto it = list.begin(); it < list.end(); it++) {
		tree.insert(*it);
		//format::printTree(tree.root, tree.count);
	}

	format::printTree(tree.root, tree.count);

	//tree.insert(80);

	return 0;
}

