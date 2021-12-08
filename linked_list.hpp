

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
	traditionally implemented, but, I'm not like
	the other girls xd*/
	int size = 0;
	int index = 0;

	void iterate(int pos);

public:
	void push_back(T elem) { insert(elem, size - 1); }
	void insert(T elem, int pos);
	void remove(int pos);
	void pop_back() { remove(size - 1); }

	T& get(int pos);
};