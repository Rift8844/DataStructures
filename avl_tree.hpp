
#include <optional>

template<typename T> struct Node {
	T elem;
	T* parent = nullptr;
	T* son, daughter = nullptr;

	void place(T* loc);
	inline bool hasParent() { return parent != nullptr; }
	inline bool hasSon() { return son != nullptr; }
	inline bool hasDaughter() { return daughter != nullptr; }
	inline bool hasChild() { return hasSon() || hasDaughter(); }

	inline bool isSon() { return hasParent() && this == parent->son; }
	inline bool isDaughter() { return hasParent() && this == parent->daughter; }

	Node(T _elem) : elem{_elem} {};
}

template<typename T> class AvlTree {
	T* root;

public:
	void insert(T elem);
}