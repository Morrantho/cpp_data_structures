#include "Node.h"

template<typename T>
Node<T>::Node(T value)
{
	next = 0;
	this->value = value;
}

template<typename T>
Node<T>::~Node()
{
	delete next;
	next = 0;
}