#include "avl_tree.hpp"
#include <iostream>
#include <cmath>

#pragma once

template<typename T> void AvlTree<T>::insert(T elem) {
	count++;

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

	balance(newNode, false);
}

//loool this is a mess
template<typename T> void AvlTree<T>::rotRight(Node<T>* pivot) {
	rRots++;
	//swap(pivot, pivot->son);
	//swap(pivot->son->son, pivot->daughter);
	Node<T>* parent = pivot->parent;

	if (parent != root) {
		parent->parentSelfPtr() = pivot;
		pivot->parent = pivot->grandparent();
	} else {
		pivot->parent = nullptr;
		root = pivot;
	}

	parent->parent = pivot;
	
	if (pivot->daughter)
		pivot->daughter->parent = parent;
	
	parent->son = pivot->daughter;

	pivot->daughter = parent;
}

template<typename T> void AvlTree<T>::rotLeft(Node<T>* pivot) {
	lRots++;

	Node<T>* parent = pivot->parent;

	if (parent != root) {
		parent->parentSelfPtr() = pivot;
		pivot->parent = pivot->grandparent();
	} else {
		pivot->parent = nullptr;
		root = pivot;
	}

	parent->parent = pivot;


	//Assign the pivot's son as the old parent's daughter
	if (pivot->son)
		pivot->son->parent = parent;

	parent->daughter = pivot->son;


	pivot->son = parent;
}

//Maybe try to optimize these later
template<typename T> void AvlTree<T>::rotLR(Node<T>* pivot) {
	lRots--;
	rRots--;
	lrRots++;
	rotLeft(pivot);
	rotRight(pivot);
}

template<typename T> void AvlTree<T>::rotRL(Node<T>* pivot) {
	rRots--;
	lRots--;
	rlRots++;
	rotRight(pivot);
	rotLeft(pivot);
}

template<typename T> void AvlTree<T>::balance(Node<T>* node, bool subMode) {
	Node<T>* current = node;

	//Update balance factors until
	while (current != root && abs(current->bal) < 2) {
		int oldBal = current->parent->bal;
		current->parent->bal += current->isSon()^subMode ? -1 : 1;

		//The tree hasn't become less balanced
		if (abs(current->parent->bal) < abs(oldBal))
			break;

		current = current->parent;
	}
	if (current->bal > 1) {

		current = current->daughter;

		if (current->bal > 0) {
			rotLeft(current);
			current->son->bal -= 2;
		} else {
			rotRL(current->son);
			current->bal++;
			current->parent->son->bal -= 2;
		}

		balance(node, true);
	} else if (current->bal < -1) {

		current = current->son;

		if (current->bal < 0) {
			rotRight(current);
			current->daughter->bal += 2;
		} else {
			rotLR(current->daughter);
			current->bal--;
			current->parent->daughter->bal += 2;
		}

		balance(node, true);
	}
}

//Consider changing to std::unique_ptr<T>
//This is unused right now
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