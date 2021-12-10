
avl_demo: avl_demo.o
	g++ -g avl_demo.o -o avl_demo

avl_tree_impl.hpp.gch: avl_tree_impl.hpp
	g++ -g avl_tree_impl.hpp

avl_tree.hpp.gch: avl_tree.hpp
	g++ -g avl_tree.hpp

avl_demo.o: avl_demo.cpp avl_tree_impl.hpp.gch 
	g++ -g -c avl_demo.cpp


list_demo: list_demo.o
	g++ -g list_demo.o -o list_demo

linked_list_impl.hpp.gch: linked_list_impl.hpp
	g++ -g linked_list_impl.hpp

linked_list.hpp.gch: linked_list.hpp
	g++ -g linked_list.hpp

list_demo.o: list_demo.cpp linked_list_impl.hpp.gch 
	g++ -g -c list_demo.cpp

clean:
	rm avl_demo *.o *.hpp.gch