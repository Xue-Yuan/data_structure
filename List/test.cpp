#include <iostream>
#include "algorithm.h"
#include "algorithm.cpp"
#include <list>
#include <vector>

using std::cin; using std::cout; using std::endl;

int main()
{
	List<int> lst;
	lst.addToTail(1);
	lst.addToTail(3);
	lst.addToTail(5);
	lst.addToTail(7);
	lst.addToTail(8);
	lst.print();
	auto ptr = lst.getPtr(3);
	ptr = lst.erase(ptr);
	cout << ptr->getInfo() << endl;
	lst.reverse();
	lst.print();
	// std::list<int> lst = {22,22,3,2,3,4,5,4,3,10};
	// lst.remove_if([](int i)->bool {return i < 10;});
	// for(auto & val : lst)
	// 	cout << val << ' ';
	// cout << endl;
	//
	// std::vector<int> vec = {22,22,3,2,3,4,5,4,3,10};
	// auto itr = vec.begin();
	// advance(itr, 2);
	// cout << *itr << endl;
	// vec.erase(remove_if(vec.begin(), vec.end(), [](int i)->bool {return i < 10;}),vec.end());
	// for(auto & val : vec)
	// 	cout << val << ' ';
	// cout << endl;
	return 0;
}