#ifndef LIST_H
#define LIST_H
#include <iostream>

template<class T>
class Node
{
public:
	T info;
	Node<T> *prev, *next;
	Node():prev(nullptr), next(nullptr){}
	Node(const T &val, Node<T> *p = nullptr, Node<T> *n = nullptr):info(val), prev(p), next(n){}

	T &getInfo() {return info;}
};


template<class T>
class List
{
private:
	Node<T> *head, *tail;
	unsigned size;
public:
	bool isEmpty() const {return head->next == tail;}
	List():size(0)
	{
		head = new Node<T>; 
		tail = new Node<T>; 
		head->next = tail;
		tail->prev = head;
	}
	List(T val):size(0)
	{
		head = new Node<T>;
		tail = new Node<T>;
		Node<T> *tmp = new Node<T>(val);
		head->next = tmp;
		tmp->next = tail;
		tail->prev = tmp;
		tmp->prev = head;
	}
	~List();
	void makeEmpty();	
	void addToHead(const T&);
	void addToTail(const T&);
	void print() const;
	void rprint() const;
	bool deleteFromHead();
	bool deleteFromTail();
	void reverse();
	unsigned getSize() {return size;};
	Node<T> *getPtr(int n);
	Node<T> *erase(Node<T> *&ptr);
	Node<T> *insert(Node<T> *&ptr, const T&);
	
};

#endif