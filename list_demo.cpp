
#include <iostream>
#include "linked_list_impl.hpp"

int main() {

	LinkedList<std::string> list;
	list.insert("Hello");
	list.insert("list");
	list.insert("world!", 1);
	list.insert("of", 2);
	list.insert("s");

	std::cout << list.get(0) << ' ' << list.get(1) << ' ' << list.get(2) << 
	' ' << list.get(3) << list.get(4) << std::endl;
	

	return 0;
}