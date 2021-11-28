#include <cstdint>

#pragma once

template<typename T> struct Node {
	T elem;

	Node<T>* parent = nullptr;
	Node<T>* son = nullptr;
	Node<T>* daughter = nullptr;

	int8_t bal = 0;

	inline bool hasParent() { return parent != nullptr; }
	inline bool hasSon() { return son != nullptr; }
	inline bool hasDaughter() { return daughter != nullptr; }
	inline bool hasChild() { return hasSon() || hasDaughter(); }

	inline bool isSon() { return hasParent() && this == parent->son; }
	inline bool isDaughter() { return hasParent() && this == parent->daughter; }

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
	int count = 0;
	Node<T>* root = nullptr;

	/*Do NOT drop the returned pointer without
	freeing, or you will leak memory. Don't do it.
	DON'T YOU DARE DROP THE FUCKING POINTER*/
	void swap(Node<T>* node, Node<T>* loc);
	void balance(Node<T>* node);

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