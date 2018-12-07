#include "Node.h"
#include <iostream>

template<typename T>
Node<T>::Node(T value)
{
	std::cout << "NODE CTOR\n";
	next = 0;
	previous = 0;
	this->value = value;
}

template<typename T>
Node<T>::~Node()
{
	std::cout << "NODE DTOR\n";
	delete previous;
	next = 0;
	previous = 0;
}