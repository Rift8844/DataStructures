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

bool checkTree(Node<int>* node) {
	static int depth = 0;

	depth++;

	if (node->hasSon()) {
		checkTree(node->son);

		if (node->son->parent != node)
			return false;
	}

	if (node->hasDaughter()) {
		checkTree(node->daughter);

		if (node->daughter->parent != node)
			return false;
	}

	depth--;

	return true;
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
	best quality code that I've ever written.
	**To be fair** though, this is one of the
	most advanced projects, if not the most
	advanced project, that I've ever worked on!*/
	AvlTree<int> tree;

	/*List of bad seeds:
	1639449189

	Good seeds:
	1639449241*/

	uint64_t systime = time(NULL);

	srand(1639449189);

	//std::cout << systime << std::endl;

	int constexpr numTests = 50;

	std::array<int, numTests> list;
	std::cout << "Test seed: " << systime << 
	"Number test suite: \n";

	for (int i = 0; i < numTests; i++) {
		int x = rand() % 100;
		//std::cout << x << std::endl;
		list[i] = x;
	}


	for (auto it = list.begin(); it < list.end(); it++) {
		std::cout << "\n\nInsertee: " << *it << std::endl;

		tree.insert(*it);

		format::printTree(tree.root, tree.count);
		tree.print();

		
		if (!checkTree(tree.root))
			throw std::exception();
	}


	format::printTree(tree.root, tree.count);
	checkTree(tree.root);

	std::cout << "Number of elements in tree: " << tree.count << std::endl;
	int maxIterCount = 0;
	for (int i = 0; i < numTests; i++) {
		maxIterCount = std::max(maxIterCount, testSearch(tree.root, list[i], true));
	}

	std::cout << "Rotation type counts:\nright: " << tree.rRots <<
	"\nleft: " << tree.lRots << "\nrightLeft: " << tree.rlRots <<
	"\nleftRight: " << tree.lrRots << std::endl;
	std::cout << "Most iterations needed for a search: " << maxIterCount << std::endl;

	/*	DET SOM ENGANG VAR HITS SO HARD,
	like, DEFINITELY BETTER THAN I REMEMBERED!
	Also, I'm listening to it on my CALs,
	and while it sounds better on my 6XXs,
	it stil sounds pretty good on my new pair
	of cans.*/
	return 0;
}