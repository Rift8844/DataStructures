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
	//The depth hasn't changed

	while (current != root) {
		current->parent->bal += current->isSon() ? -1 : 1;
		if (current->parent->bal > 0 == current->isSon() ||
			current->parent->bal == 0)
			break;

		current = current->parent;
	}
}

//loool this is a mess
template<typename T> void AvlTree<T>::rotRight(Node<T>* pivot) {
	//swap(pivot, pivot->son);
	//swap(pivot->son->son, pivot->daughter);
	Node<T>* parent = pivot->parent;
	Node<T>* grandparent = pivot->grandparent();

	if (parent != root) {
		parent->parentSelfPtr() = pivot;
		pivot->parent = grandparent;
	} else {
		pivot->parent = nullptr;
		root = pivot;
	}

	parent->parent = pivot;
	//Pivot shouldn't have a son
	pivot->daughter = parent;


	parent->son = nullptr;
}

template<typename T> void AvlTree<T>::rotLeft(Node<T>* pivot) {
	Node<T>* parent = pivot->parent;
	Node<T>* grandparent = pivot->grandparent();

	if (parent != root) {
		parent->parentSelfPtr() = pivot;
		pivot->parent = grandparent;
	} else {
		pivot->parent = nullptr;
		root = pivot;
	}


	parent->parent = pivot;
	pivot->son = parent;

	//Pivot shouldn't have a daughter
	parent->daughter = nullptr;
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