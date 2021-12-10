

template<typename T> class LinkedList {
	template<typename> struct Node {
		Node<T>* prev;
		Node<T>* next;
		T value;
	};

	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;

	Node<T>* current = head;

	/*I know this isn't how a linked list is
	traditionally implemented, but, I'm uhh...
	I guess like I'm not like the other rawr girls xd*/
	int size = 0;
	int index = -1;

	void iterate(int pos);

public:
	void insert(T elem) { insert(elem, size); }
	void insert(T elem, int pos);
	//void remove(int pos);
	void pop_back() { remove(size - 1); }

	T& get(int pos);
};