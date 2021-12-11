#include "linked_list.hpp"
#include <exception>

template<typename T> void LinkedList<T>::insert(T elem, int pos) {
	//If something goes terribly wrong, you'll get a null pointer exception
	iterate(pos);

	Node<T>* node = new Node<T>;
	node->value = elem;

	if (size == 0) {
		current = node;
		index++;

		head = current;
		tail = current;
		size++;

		return;
	}

	//Node is inserted at the front
	if (pos == size) {
		node->prev = current;
		current->next = node;

		node->next = nullptr;

		tail = node;
	} else {
		/*When insertion is done, the node at
		the index the new node is being inserted
		is put **ahead** of the new node*/
		node->prev = current->prev;
		node->next = current;

		if (node->prev == nullptr) {
			tail = node;
		} else {
			current->prev->next = node;
		}

		current->prev = node;
	}



	current = node;

	index = pos;
	size++;
}

/*template<typename T> void LinkedList<T>::remove(int pos) {
	iterate(pos);
	size--;

	if (current != head) {
		current->prev->next = current->next;
	} else if (current != tail) {
		head = head->next;
	}

	if (current != tail) {
		current->next->prev = current->prev;
	} else if (current != head) {
		tail = tail->prev;
	}

	Node<T>* tmp = current->prev;
	delete current;

	index--;
}*/


template<typename T> T& LinkedList<T>::get(int pos) {
	iterate(pos);

	return current->value;
}


template<typename T> void LinkedList<T>::iterate(int pos) {
	if (pos < -1 || pos > size)
		throw std::exception();

	if (index > pos) {
		for (; index > pos; index--) {
			current = current->prev;
		}
	} else {
		for (; index < pos && index < size - 1; index++) {
			current = current->next;
		}
	}
}