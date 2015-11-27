#include <iostream>
#include "algorithm.h"
#include "inorder_morris_traversal.cpp"

using std::cin; using std::cout; using std::endl;

int main()
{
	BinarySearchTree<int> bst1, bst2;
	for(int i = 0; i < 10; ++i)
	{
		bst1.insert(i);
	}
	bst1.preOrder();
	return 0;
}