
template<typename T> struct Node {
	T elem;
	T* parent = nullptr;
	T* son, daughter = nullptr;
}

template<typename T> class AvlTree {
	T* root;
}