#include <cstdint>

#pragma once

template<typename T> struct Node {
	T elem;

	Node<T>* parent = nullptr;
	Node<T>* son = nullptr;
	Node<T>* daughter = nullptr;

	int8_t bal = 0;

	//Non inline for debug purposes
	bool hasParent() { return parent != nullptr; }
	bool hasSon() { return son != nullptr; }
	bool hasDaughter() { return daughter != nullptr; }
	bool hasChild() { return hasSon() || hasDaughter(); }

	bool isSon() { return hasParent() && this == parent->son; }
	bool isDaughter() { return hasParent() && this == parent->daughter; }
	Node<T>* grandparent() { return parent->parent; } 

	/*The pointer the parent holds to this node.
	The absence of a third ternary statement is intentional,
	as if parent->daughter does not exist, it will return a nullptr
	anyway. Will throw a null pointer exception if this is the root node.*/
	Node<T>*& parentSelfPtr() { return isSon() ? parent->son : parent->daughter; }
	
	
	Node(T _elem) : elem{_elem} {};
};

template<typename T> class AvlTree {
	//Tree depth

public:
	//Debug info
	int count = 0;
	int rlRots = 0;
	int lrRots = 0;
	int rRots = 0;
	int lRots = 0;
	//----------------------
	Node<T>* root = nullptr;

	/*Do NOT drop the returned pointer without
	freeing, or you will leak memory. Don't do it.
	DON'T YOU DARE DROP THE FUCKING POINTER*/
	void swap(Node<T>* node, Node<T>* loc);
	void balance(Node<T>* node, bool subMode);

	void rotRight(Node<T>* node);
	void rotLeft(Node<T>* node);
	void rotRL(Node<T>* node);
	void rotLR(Node<T>* node);

	void print_(Node<T>* node);
//public:
	void insert(T elem);
	void print() { print_(root); }

	Node<T>* getRoot() { return root; }

};