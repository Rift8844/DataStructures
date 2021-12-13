#include "avl_tree_impl.hpp"
#include "prettyprinter.hpp"
#include "linked_list_impl.hpp"
#include <time.h>
#include <climits>
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
	static int depth = 0;

	depth++;

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

	depth--;

	if (depth == 0) {
		std::cout << "All checks passed!" << std::endl;
	}
}


//I'm an idiot... you can't catch seg faults!
uint64_t findBadSeed(int numTests) {
	uint64_t worstSeed = time(NULL);
	int worstInserts = 128;

	uint64_t currentSeed = worstSeed;

	for (int j = 0; j < numTests; j++) {
		AvlTree<int> tree;

		srand(currentSeed);

		int i = 1;
		try {
			for (; i <= worstInserts; i++) {
				tree.insert(rand() % 100);
			}
		} catch(std::exception& e) {}

		if (i < worstInserts)  {
			worstSeed = currentSeed;
			worstInserts = i;
		}
	}

	return worstSeed;
}

int testSearch(Node<int>* node, int num, bool isRoot = false) {
	static int iters;
	if (isRoot)
		iters = 0;

	if (node->elem < num) {
		iters++;
		return testSearch(node->daughter, num);
	} else if (node->elem > num) {
		iters++;
		return testSearch(node->son, num);
	} else {
		return iters;
	}
}

int main() {
	/*Ok I'll acknowledge that this isn't the
	best quality code that I've ever written lol*/
	AvlTree<int> tree;

	constexpr uint64_t badSeed = 1638737580;
	uint64_t systime = time(NULL);

	srand(systime);

	//std::cout << systime << std::endl;

	std::array<int, 20> list;
	std::cout << "Number test suite: \n";

	for (int i = 0; i < 20; i++) {
		int x = rand() % 100;
		//std::cout << x << std::endl;
		list[i] = x;
	}


	for (auto it = list.begin(); it < list.end(); it++) {
		std::cout << *it << std::endl;
		tree.insert(*it);
		//format::printTree(tree.root, tree.count);
	}


	format::printTree(tree.root, tree.count);
	checkTree(tree.root);

	std::cout << "Number of elements in tree: " << tree.count << std::endl;
	int maxIterCount = 0;
	for (int i = 0; i < 20; i++) {
		maxIterCount = std::max(maxIterCount, testSearch(tree.root, list[i], true));
	}

	std::cout << "Rotation type counts:\nright: " << tree.rRots <<
	"\nleft: " << tree.lRots << "\nrightLeft: " << tree.rlRots <<
	"\nleftRight: " << tree.lrRots << std::endl;
	std::cout << "Most iterations needed for a search: " << maxIterCount << std::endl;


	return 0;
}

