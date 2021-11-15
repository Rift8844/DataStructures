
#include "avl_tree.hpp"
#include <iostream>

template<typename T> void AvlTree<T>::insert(T elem) {
	Node<T>* newNode = new Node<T>(elem);
	if (!root) {
		root = newNode;
		return;
	}

	Node<T>* current = root;

	//Traverse the tree until we find a node without two children
	while (true) {
		static Node<T>* prev;
		prev = current;
		current = newNode->elem <= current->elem ? current->son : current->daughter;

		if (current == nullptr) {
			current = prev;
			break;
		}
	}

	//Have the node with an extra child slot adopt the new node
	if (newNode->elem <= current->elem)
		current->son = newNode;
	else
		current->daughter = newNode;

	newNode->parent = current;


	current = newNode;
	//Update balance factors
	while (current != root) {
		current->parent->bal += current->isSon() ? -1 : 1;
		current = current->parent;
	}
}

template<typename T> void AvlTree<T>::print_(Node<T>* node) {
		if (node->hasSon())
			print_(node->son);

		if (node->hasDaughter())
			print_(node->daughter);

		std::cout << 
		"------" << 
		"\nValue: " << node->elem <<
		"\nBalance: " << (int16_t) node->bal << std::endl;
	}