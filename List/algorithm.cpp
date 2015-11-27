#include "algorithm.h"

template <class T>
void List<T>::makeEmpty()
{
	if(isEmpty())	return;
	Node<T> *tmp = head->next;
	while(tmp != tail)
	{
		Node<T> *curr = tmp;
		tmp = tmp->next;		
		delete curr;
	}
	head->next = tail;
	tail->prev = head;
	size = 0;
}

template <class T>
List<T>::~List()
{
	makeEmpty();
	delete head;
	delete tail;
}

template <class T>
void List<T>::addToHead(const T &val)
{
	++size;
	if(isEmpty())
	{
		Node<T> *tmp = new Node<T>(val, head, tail);
		head->next = tmp;
		tail->prev = tmp;
		return;
	}
	Node<T> *tmp = new Node<T>(val, head); //tmp->prev = head;
	tmp->next = head->next;
	tmp->next->prev = tmp;
	head->next = tmp;
}

template <class T>
void List<T>::addToTail(const T &val)
{
	++size;
	if(isEmpty())
	{
		Node<T> *tmp = new Node<T>(val, head, tail);
		head->next = tmp;
		tail->prev = tmp;
		return;
	}
	Node<T> *tmp = new Node<T>(val);
	tmp->next = tail;
	tmp->prev = tail->prev;
	tmp->prev->next = tmp;
	tail->prev = tmp;
}

template <class T>
void List<T>::print() const
{
	if(isEmpty()) std::cout << "Empty List!!!" << std::endl;
	Node<T> *tmp = head;
	while(tmp->next != tail)
	{
		tmp = tmp->next;		
		std::cout << tmp->getInfo() << ' ';
	}
	std::cout << std::endl;
}

template <class T>
void List<T>::rprint() const
{
	if(isEmpty()) std::cout << "Empty List!!!" << std::endl;
	Node<T> *tmp = tail;
	while(tmp->prev != head)
	{
		tmp = tmp->prev;
		std::cout << tmp->getInfo() << ' ';
	}
	std::cout << std::endl;
}

template <class T>
bool List<T>::deleteFromHead()
{
	if(isEmpty()) return false;
	Node<T> *tmp = head->next;
	head->next = tmp->next;
	tmp->next->prev = head;
	delete tmp;
	--size;
	return true;	
}

template <class T>
bool List<T>::deleteFromTail()
{
	if(isEmpty()) return false;
	Node<T> *tmp = tail->prev;
	tail->prev = tmp->prev;
	tmp->prev->next = tail;
	delete tmp;
	--size;
	return true;
}

//insert val before the Node denoted by ptr
template <class T>
Node<T> *List<T>::insert(Node<T> *&ptr, const T &val)
{
	Node<T> *tmp = new Node<T>(val);
	tmp->prev = ptr->prev;
	tmp->next = ptr;
	tmp->prev->next = tmp;
	tmp->next->prev = tmp;
	++size;
	return tmp;
}

//erase Node denoted by ptr, return pointer to the Node after ptr
template <class T>
Node<T> *List<T>::erase(Node<T> *&ptr)
{
	if(isEmpty()) return nullptr;
	if(ptr == head || ptr == tail) return nullptr;
	ptr->next->prev = ptr->prev;
	Node<T> *tmp = ptr->next;
	ptr->prev->next = ptr->next;
	delete ptr;
	return tmp;	
}

//return the n th pointer
template <class T>
Node<T> *List<T>::getPtr(int n)
{
	if(n > size) return nullptr;
	Node<T> *tmp = head->next;
	for(int i = 0; i < n-1; ++i)	tmp = tmp->next;
	return tmp;
}

template <class T>
void List<T>::reverse()
{
	if(isEmpty()) return;
	Node<T> *tmp = head->next;
	while(tmp != tail)
	{
		
		this->addToHead(tmp->getInfo());
		tmp = this->erase(tmp);
	}
}
