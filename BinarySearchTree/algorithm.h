#ifndef STACK_H
#define STACK_H
#include <iostream>
using std::cin; using std::cout; using std::endl;

template <class Comparable>
struct BinaryNode
{
	Comparable elem;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(const Comparable &theElem, BinaryNode *lt, BinaryNode *rt)
		:elem(theElem), left(lt), right(rt) {}
	BinaryNode(Comparable &&theElem, BinaryNode *lt, BinaryNode *rt)
		:elem(std::move(theElem)), left(lt), right(rt){}
};

template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree():root(nullptr){}
	BinarySearchTree(const BinarySearchTree &rhs);
	BinarySearchTree(BinarySearchTree &&rhs);
	~BinarySearchTree() {makeEmpty();}

	const Comparable &findMin() const;
	const Comparable &findMax() const;
	bool contains(const Comparable &x) const;
	bool isEmpty() const {return root == nullptr;};
	void preOrder(std::ostream &out = std::cout) const;

	void makeEmpty() {makeEmpty(root);}
	void insert(const Comparable &x);
	void insert(Comparable &&x);
	void remove(const Comparable &x);

	/*** undefined yet ***/
	BinarySearchTree &operator=(const BinarySearchTree &rhs);
	BinarySearchTree &operator=(BinarySearchTree &&rhs);
	/*** undefined yet ***/

private:

	BinaryNode<Comparable> *root;

	void insert(const Comparable &rhs, BinaryNode<Comparable> *&t);
	void insert(Comparable &&rhs, BinaryNode<Comparable> *&t);
	void remove(const Comparable &x, BinaryNode<Comparable> *&t);
	BinaryNode<Comparable> *findMin(BinaryNode<Comparable> *t) const;
	BinaryNode<Comparable> *findMax(BinaryNode<Comparable> *t) const;
	bool contains(const Comparable &x, BinaryNode<Comparable> *&t);
	void makeEmpty(BinaryNode<Comparable> *&t);
	void preOrder(BinaryNode<Comparable> *t, std::ostream &out) const;
	BinaryNode<Comparable> *clone(BinaryNode<Comparable> *t) const;
};

#endif
