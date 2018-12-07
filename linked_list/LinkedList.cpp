#include "LinkedList.h"
#include <iostream>

template<typename T>
LinkedList<T>::LinkedList()
{
	head = 0;
	tail = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	delete head;
	head = 0;
	tail = 0;
}

template<typename T>
Node<T>* LinkedList<T>::Add(T value)
{
	if(head == 0 || tail == 0){ 
		head = new Node<T>(value);
		tail = head;
		return tail;
	}

	Node<T>* t = tail;
	t->next = new Node<T>(value);
	t->next->previous = t;
	tail = t->next;
	return tail;
}

template<typename T>
bool Reassign(Node<T>* h)
{
	h->previous->next = h->next;
	h->next->previous = h->previous;
	h->previous = 0;
	h->next = 0;
	delete h;

	return true;
}

template<typename T>
bool LinkedList<T>::Remove(T value)
{
	Node<T>* h = head;
	Node<T>* t = tail;

	for( ; h != t && h->next != 0 && t->previous != 0; h = h->next, t = t->previous)
		if( h->value == value ) return Reassign(h);
		if( t->value == value ) return Reassign(t);
	return false;
}

template<typename T>
bool LinkedList<T>::Contains(T value)
{
	Node<T>* h = head;
	Node<T>* t = tail;

	for( ; h != t && h->next != 0 && t->previous != 0; h = h->next, t = t->previous)
		if(h->value == value || t->value == value)
			return true;

	return false;
}

template<typename T>
Node<T>* LinkedList<T>::Find(T value)
{
	Node<T>* h = head;
	Node<T>* t = tail;

	for( ; h != t && h->next != 0 && t->previous != 0; h = h->next, t = t->previous)
		if(h->value == value) return h;
		if(t->value == value) return t;

	return 0;
}