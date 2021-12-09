#include "linked_list.hpp"

template<typename T> void LinkedList<T>::insert(T elem, int pos) {
	//If something goes terribly wrong, you'll get a null pointer exception
	iterate(pos);
	size++;

	Node<T>* node = new Node<T>;
	node->value = elem;

	if (size == 1) {
		current = node;
		index++;

		head = current;
		tail = current;
		return;
	}

	node->prev = current;
	node->next = current->next;

	if (current != tail)
		current->next->prev = node;

	current->next = node;
}

template<typename T> void LinkedList<T>::remove(int pos) {
	iterate(pos);
	size--;

	if (current != head) {
		current->prev->next = current;
	} else if (current != tail) {
		head = head->next;
	}

	if (current != tail) {
		current->next->prev = current;
	} else if (current != head) {
		tail = tail->prev;
	}

	delete current;
}

template<typename T> T& LinkedList<T>::get(int pos) {
	iterate(pos);

	return current->value;
}


template<typename T> void LinkedList<T>::iterate(int pos) {
	if (index > pos) {
		for (; index > pos; index--)
			current = current->prev;
	} else {
		for (; index < pos; index++)
			current = current->next;
	}
}