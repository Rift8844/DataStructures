
demo: main.o avl_tree_impl.hpp.gch avl_tree.hpp.gch
	g++ -g main.o -o demo

avl_tree_impl.hpp.gch: avl_tree_impl.hpp
	g++ avl_tree_impl.hpp

avl_tree.hpp.gch: avl_tree.hpp
	g++ avl_tree.hpp


main.o: main.cpp avl_tree_impl.hpp.gch 

clean:
	rm demo *.o *.hpp.gch