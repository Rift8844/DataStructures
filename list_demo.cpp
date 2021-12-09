
#include <iostream>
#include "linked_list_impl.hpp"

int main() {

	LinkedList<std::string> list;
	list.insert("Hello");
	list.insert("world!");
	list.insert("linked list");

	std::cout << list.get(0) << ' ' << list.get(1) << ' ' << list.get(2) << std::endl;
	

	return 0;
}