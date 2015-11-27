/*
ForwardList

*/
#ifndef ForwardList_H
#define ForwardList_H

template<class T>
class Node
{
public:
	Node<T> *next;
	T info;
	Node():next(nullptr){}
	Node(T i):info(i), next(nullptr){}
	T &getInfo() {return info;}
};
/*
There is always a head Node, for the convience of operating.
But the element starts from head->next.
If head == tail, then empty.
*/
template<class T>
class ForwardList
{
private:
	Node<T> *head, *tail;
public:
	ForwardList(){head = tail = new Node<T>;}
	ForwardList(T &val)
	{
		tail = new Node<T>(val);
		head = new Node<T>(val, tail);
	}
	~ForwardList();
	void makeEmpty();
	bool isEmpty() const{return head == tail;}
	bool deleteFromHead();
	bool deleteFromTail();
	Node<T> *isInList(const T &) const;
	void addToHead(T);
	void addToTail(T);
	void print();
};

#endif