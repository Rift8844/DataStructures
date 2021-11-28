#include "avl_tree_impl.hpp"
#include "prettyprinter.hpp"
#include <iostream>
#include <array>


template<typename T> std::ostream& operator<<(std::ostream& os, Node<T>* node) {
	return os << "------\nValue: " << std::dec << node->elem <<
	"\nParent address: " << std::hex << reinterpret_cast<uint16_t> (node->parent)
	<< "\nSon address: " << std::hex << reinterpret_cast<uint16_t> (node->son) <<
	"\nDaughter address: " << std::hex << reinterpret_cast<uint16_t> (node->daughter) << 
	"\n------" << std::endl;

}

int main() {

	AvlTree<int> tree;
	std::array<int, 11> list { 20, 25, 15, 10, 12, 60, 82, 49, 1, 11, 5 };

	for (auto it = list.begin(); it < list.end(); it++) {
		tree.insert(*it);
	}
	/*
	for (int i = 0; i < 15; i++) {
		int j = rand() % 100;
		tree.insert(j);
	}*/
	//tree.insert(80);

	format::printTree(tree.root, list.size());

	tree.print();

	tree.rotLR(tree.root->son->son->daughter);
	format::printTree(tree.root, list.size());

	return 0;
}

