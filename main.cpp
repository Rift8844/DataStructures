#include "avl_tree_impl.hpp"
#include <iostream>

int main() {

	AvlTree<int> tree;
	for (int i = 0; i <= 25; i++) {
		tree.insert(i);
		tree.insert(-i);
	}

	tree.print();

	std::cout << "Hello world of data structures!" << std::endl;

	return 0;
}