#include <cstdint>

template<typename T> struct Node {
	T elem;

	Node<T>* parent = nullptr;
	Node<T>* son = nullptr;
	Node<T>* daughter = nullptr;

	int8_t bal = 0;


	void place(T* loc);
	inline bool hasParent() { return parent != nullptr; }
	inline bool hasSon() { return son != nullptr; }
	inline bool hasDaughter() { return daughter != nullptr; }
	inline bool hasChild() { return hasSon() || hasDaughter(); }

	inline bool isSon() { return hasParent() && this == parent->son; }
	inline bool isDaughter() { return hasParent() && this == parent->daughter; }

	Node(T _elem) : elem{_elem} {};
};

template<typename T> class AvlTree {
	Node<T>* root = nullptr;

	void print_(Node<T>* node);
public:
	void insert(T elem);
	void print() {	print_(root); }

};