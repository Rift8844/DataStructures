#include "avl_tree.hpp"
#include <iostream>

#pragma once

template<typename T> void AvlTree<T>::insert(T elem) {
	Node<T>* newNode = new Node<T>(elem);
	if (!root) {
		root = newNode;
		return;
	}

	Node<T>* current = root;

	//Traverse the tree until we find a node who can adopt this node
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

template<typename T> void AvlTree<T>::rotRight(Node<T>* pivot) {
	Node<T>* parent = pivot->parent;
	Node<T>* grandparent = parent->parent;

	pivot->parent = grandparent;
}


//Consider changing to std::unique_ptr<T>
template<typename T> void
AvlTree<T>::swap(Node<T>* node1, Node<T>* node2) {

	std::swap(node1->parentSelfPtr(), node2->parentSelfPtr());
	std::swap(node1->parent, node2->parent);

	std::swap(node1->son, node2->son);
	std::swap(node1->daughter, node2->daughter);

	if (node1->son)
		node1->son->parent = node1;
	if (node1->daughter)
		node1->daughter->parent = node1;

	if (node2->son)
		node2->son->parent = node2;
	if (node2->daughter)
		node2->daughter->parent = node2;

	std::swap(node1->bal, node2->bal);
	
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