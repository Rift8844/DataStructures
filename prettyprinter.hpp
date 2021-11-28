#include <iomanip>
#include <vector>
#include <iostream>
#include "avl_tree_impl.hpp"

/*Don't be a bad kid
Or you'll be put inside the corner
Now my former friends is acting like I owe them shit
Had to grow then split
Like mitosis or division
You don't know this you ain't listen
On the slow end bitch*/

//This BARELY WORKS
namespace format {
	//Curse whoever the fuck wrote this code

	// create a pretty vertical tree
	template<typename T> void printTree(Node<T> *p, int nodeCount)
	{	
		for (int i = 0 ; i < nodeCount; i++) {
	 		printRow(p, nodeCount, i);
		}
	}


	template<typename T> void printRow(const Node<T> *p, const int height, int depth)
	{
			T placeholder = T();

	        std::vector<int> vec;
	        getLine(p, depth, vec);
	        std::cout << std::setw((height - depth)*2); // scale std::setw with depth
	        bool toggle = true; // start with son
	        if (vec.size() > 1) {
	                for (int v : vec) {
	                        if (v != placeholder) {
	                                if (toggle)
	                                        std::cout << "/" << "   ";
	                                else
	                                        std::cout << "\\" << "   ";
	                        }
	                        toggle = !toggle;
	                }
	                std::cout << std::endl;
	                std::cout << std::setw((height - depth)*2);
	        }
	        for (int v : vec) {
	                if (v != placeholder)
	                        std::cout << v << "   ";
	        }
	        std::cout << std::endl;
	}

	template<typename T> void getLine(const Node<T> *root, int depth, std::vector<T>& vals)
	{
			T placeholder = T();

	        if (depth <= 0 && root != nullptr) {
	                vals.push_back(root->elem);
	                return;
	        }
	        if (root->son != nullptr)
	                getLine(root->son, depth-1, vals);
	        else if (depth-1 <= 0)
	                vals.push_back(placeholder);
	        if (root->daughter != nullptr)
	                getLine(root->daughter, depth-1, vals);
	        else if (depth-1 <= 0)
	                vals.push_back(placeholder);
	}
}