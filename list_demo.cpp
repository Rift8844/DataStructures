
#include <iostream>
#include "linked_list_impl.hpp"

int main() {

	LinkedList<std::string> list;
	list.insert("Hello");
	list.insert("list");
	list.insert("world", 1);
	list.insert("of", 2);
	list.insert("s");
	list.insert("THIS SHOULDNT BE HERE");
	list.remove(5);

	std::cout << list.get(0) << ' ' << list.get(1) << ' ' << list.get(2) << 
	' ' << list.get(3) << list.get(4) << std::endl;

	for (int i = 0; i < 5; i++) {
		list.pop_back();
	}

	list.insert("Done!");
	std::cout << list.get(0) << std::endl;
	std::cout << list.get(1);

	return 0;
}