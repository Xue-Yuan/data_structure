#include "algorithm.h"
#include <stack>

using std::cin; using std::cout; using std::endl;
/***** public member below ******/
template <class T>
bool BinarySearchTree<T>::contains(const T &x) const
{
	return contains(x, root);
}

template <class T>
void BinarySearchTree<T>::insert(const T &x)
{
	insert(x, root);
}

template <class T>
void BinarySearchTree<T>::insert(T &&x)
{
	insert(std::move(x), root);
}

template <class T>
void BinarySearchTree<T>::remove(const T &x)
{
	remove(x, root);
}

template <class T>
const T &BinarySearchTree<T>::findMin() const
{
	return findMin(root)->elem;
}

template <class T>
const T &BinarySearchTree<T>::findMax() const
{
	return findMax(root)->elem;
}

template <class T>
void BinarySearchTree<T>::preOrder(std::ostream &out) const
{
	preOrder(root, out);
}
/****** public member above *******/

/***** private member below ******/

template <class T>
bool BinarySearchTree<T>::contains(const T &x, BinaryNode<T> *&t)
{
	if(t == nullptr) return false;
	if(t->elem < x)
		return contains(x, t->right);
	else if(t->elem > x)
		return contains(x, t->left);
	else
		return true;
/*
	if(t == nullptr) return false;
	auto tmp = t;
	while(tmp->elem != x)
	{
		if(tmp->elem > x)
		{
			if(tmp->left == nullptr) return false;
			tmp = tmp->left;
		}
		else
		{
			if(tmp->right == nullptr) return false;
			tmp = tmp->right;
		}
	}
	return true;
*/
}

template <class T>
BinaryNode<T> *BinarySearchTree<T>::findMin(BinaryNode<T> *t) const
{
	if(t == nullptr) return nullptr;
	for(; t->left != nullptr; t = t->left);
	return t;
}

template <class T>
BinaryNode<T> *BinarySearchTree<T>::findMax(BinaryNode<T> *t) const
{
	if(t == nullptr) return nullptr;
	for(; t->right != nullptr; t = t->right);
	return t;
}

template <class T>
void BinarySearchTree<T>::insert(const T &x, BinaryNode<T> *&t)
{
	if(t == nullptr)
		t = new BinaryNode<T>(x, nullptr, nullptr);
	else if(x < t->elem)
		insert(x, t->left);
	else if(x > t->elem)
		insert(x, t->right);
	else
		;	//Duplication, do nothing
}

template <class T>
void BinarySearchTree<T>::insert(T &&x, BinaryNode<T> *&t)
{
	if(t == nullptr)
		t = new BinaryNode<T>(std::move(x), nullptr, nullptr);
	else if(x < t->elem)
		insert(std::move(x), t->left);
	else if(x > t->elem)
		insert(std::move(x), t->right);
	else
		;	//Duplication, do nothing
}

template <class T>
void BinarySearchTree<T>::remove(const T &x, BinaryNode<T> *&t)
{
	if(t == nullptr) return;
	if(x < t->elem)	remove(x, t->left);
	else if(x > t->elem) remove(x, t->right);
	else
	{
		//the point to remove has two children
		if(t->left != nullptr && t->right != nullptr)
		{
			t->elem = finMin(t->right)->elem;
			remove(t->elem, t->right);
		}
		//one child, or leaf
		else
		{
			BinaryNode<T> *old = t;
			t = (t->left != nullptr) ? t->left : t->right;
			delete old;
		}
	}

}

template <class T>
void BinarySearchTree<T>::makeEmpty(BinaryNode<T> *&t)
{
	if(t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}

//copy constructor
template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &rhs):root(nullptr)
{
	root = clone(rhs.root);
	cout << "COPY CONSTRUCTOR!" << endl;
}

//move constructor
template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T> &&rhs):root(nullptr)
{
	root = rhs.root;
	rhs.root = nullptr;
}

//copy assignment
template <class T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(const BinarySearchTree<T> &rhs)
{
	 if(this != &root)
	{
		makeEmpty(root);
		root = clone(rhs);
	}
	return *this;
}

//move assignment
template <class T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(BinarySearchTree<T> &&rhs)
{
	if(this != &rhs)
	{
		makeEmpty(root);
		root = rhs.root;
		rhs.root = nullptr;
	}
	cout << "MOVE ASSIGNMENT!" << endl;
	return *this;
}
//very slick recursion
template <class T>
BinaryNode<T> *BinarySearchTree<T>::clone(BinaryNode<T> *t) const
{
	if(t == nullptr) return nullptr;
	else
		return new BinaryNode<T>{ t->elem, clone( t->left ), clone( t->right ) };
}

template <class T>
void BinarySearchTree<T>::preOrder(BinaryNode<T> *t, std::ostream &out) const
{
	// if(!t) return;
	// out << t->elem;
	// preOrder(t->left, out);
	// preOrder(t->right, out);
	std::stack<BinaryNode<T> *> stk;

	BinaryNode<T> *p = t;

	while(p != nullptr || !stk.empty())
	{
		while(p != nullptr)
		{
			out << p->elem << ' ';
			stk.push(p);
			p = p->left;
		}
		if(!stk.empty())
		{
			p = stk.top(); 
			stk.pop();
			p = p->right;
		}
	}
	
}
/***** private member above ******/


template class BinarySearchTree<int>;
template class BinarySearchTree<double>;
