#include <iostream>
#include "algorithm1.h"

template<class T>
ForwardList<T>::~ForwardList()
{
    makeEmpty();
    delete head;
}

template<class T>
void ForwardList<T>::makeEmpty()
{
	if(isEmpty())	return;
	Node<T> *tmp = head;
	while(tmp->next != tail)
	{
		Node<T> *followTmp = tmp->next;
		tmp->next = followTmp->next;
		delete followTmp;
		if(tmp->next != tail)	tmp = tmp->next;
	}
	delete tail;
    tail = head;
}

template<class T>
bool ForwardList<T>::deleteFromHead()
{
	if(isEmpty())
		return false;
	if(head->next == tail)	{makeEmpty();return true;}
	Node<T> *tmp = head->next;
	head->next = tmp->next;
	delete tmp;
	return true;
}

template<class T>
bool ForwardList<T>::deleteFromTail()
{
	if(isEmpty())
		return false;
	if(head->next == tail)	{makeEmpty();return true;}
	Node<T> *tmp;
	for(tmp = head->next; tmp->next != tail; tmp = tmp->next);
	delete tail;
	tmp->next = nullptr;
	tail = tmp;
	return true;
}

template<class T>
void ForwardList<T>::addToHead(T val)
{
	Node<T> *tmp = new Node<T>(val);
	if(isEmpty())
	{
		head->next = tmp;
		tail = tmp;
		return;
	}
	tmp->next = head->next;
	head->next = tmp;
}

template<class T>
void ForwardList<T>::addToTail(T val)
{
	Node<T> *tmp = new Node<T>(val);
	if(isEmpty())
	{
		head->next = tmp;
		tail = tmp;
		return;
	}
	tail->next = tmp;
	tail = tmp;
}

template<class T>
void ForwardList<T>::print()
{
	if(isEmpty())	return;
	Node<T> *tmp = head;
	while(tmp->next != tail)
	{
		tmp = tmp->next;
		std::cout << tmp->getInfo() << ' ';
	}
	std::cout << tail->getInfo() << std::endl;
}

template<class T>
//find the first occurrence
//if not in ForwardList, return nullptr;
Node<T> *ForwardList<T>::isInList(const T &val) const
{
	if(isEmpty()) return nullptr;
	Node<T> *tmp = head;
	while(tmp != tail)
	{
		tmp = tmp->next;
		if(tmp->getInfo() == val)
			return tmp;
	}
	return nullptr;
}

template class ForwardList<int>;
template class ForwardList<double>;


