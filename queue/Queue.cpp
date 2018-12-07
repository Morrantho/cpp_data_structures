#include "Queue.h"

template<typename T>
Queue<T>::Queue()
{
	head = 0;
	tail = 0;
	size = 0;
}

template<typename T>
Queue<T>::~Queue()
{
	delete head;
	head = 0;
	tail = 0;
	size = 0;
}

template<typename T>
void Queue<T>::Enqueue(T value)
{
	if(head == 0 || tail == 0){ 
		head = new Node<T>(value);
		tail = head;
	}

	Node<T>* t = tail;
	t->next = new Node<T>(value);
	t->next->previous = t;
	tail = t->next;
	size++;
}

// Caller must call delete on popped node else memory leak.
template<typename T>
Node<T>* Queue<T>::Dequeue()
{
	if(size == 0) return 0;

	Node<T>* h = head;
	head = head->next;
	head->previous = 0;
	h->next = 0;
	h->previous = 0;
	size--;
	return h;
}

template<typename T>
Node<T>* Queue<T>::Peek(int n)
{
	if(n > size) return 0;
	Node<T>* h = head;
	for( ; n > 0; n--, h = h->next ){}
	return h;
}

template<typename T>
Node<T>* Queue<T>::Front()
{
	return head;
}

template<typename T>
Node<T>* Queue<T>::Back()
{
	return tail;
}


template<typename T>
bool Queue<T>::IsEmpty()
{
	return head == 0 ? 1:0;
}

// O(1/2n)
template<typename T>
int Queue<T>::Contains(T value)
{
	Node<T>* h = head;
	Node<T>* t = tail;
	int i = 0;
	int j = size-1;

	for( ; h != t && h->next != 0 && t->previous != 0; h = h->next, i++, t = t->previous, j--)
		if( h->value == value ) return i;
		if( t->value == value ) return size-j;
	return -1;
}

template<typename T>
int Queue<T>::Size()
{
	return size;
}