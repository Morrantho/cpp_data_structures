#include "Stack.h"

template<typename T>
Stack<T>::Stack()
{
	tail = 0;
	size = 0;
}

template<typename T>
Stack<T>::~Stack()
{
	delete tail;
	tail = 0;
	size = 0;
}

template<typename T>
void Stack<T>::Push(T value)
{
	size++;
	if(tail == 0)
	{
		tail = new Node<T>(value);
		return;
	}

	Node<T>* t = tail;
	t->next = new Node<T>(value);
	t->next->previous = t;
	tail = t->next;
}

// Caller needs to call delete on the popped node, else memory leak.
template<typename T>
Node<T>* Stack<T>::Pop()
{
	if(!IsEmpty())
	{
		Node<T>* top = tail;
		tail = tail->previous;
		tail->next = 0;
		top->previous = 0;
		size--;
		return top;
	}
	return 0;
}

template<typename T>
Node<T>* Stack<T>::Peek(int n)
{
	if(n > size) return 0;

	Node<T>* t = tail;
	for( ; n > 0; n--, t = t->previous) {}
	return t; // Worst case we're returning nullptr.
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return tail == 0 ? 1:0;
}

template<typename T>
int Stack<T>::Contains(T value)
{
	Node<T>* t = tail;
	int i = 0;
	
	for( ; t != 0; t = t->previous, i++)
		if(t->value == value)
			return i;
	return -1;
}

template<typename T>
int Stack<T>::Size()
{
	return size;
}