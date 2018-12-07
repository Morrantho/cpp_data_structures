#include "Node.cpp"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
struct LinkedList
{
	Node<T>* head;
	Node<T>* tail;

	LinkedList();
	~LinkedList();
	Node<T>* Add(T value);
	bool Remove(T value);
	bool Contains(T value);
	Node<T>* Find(T value);
};
#endif