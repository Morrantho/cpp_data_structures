#include "Node.h"
#include <iostream>

template<typename T>
Node<T>::Node(T value)
{
	std::cout << "NODE CTOR\n";
	left = 0;
	right = 0;
	height = 0;
	this->value = value;
}

template<typename T>
Node<T>::~Node()
{
	std::cout << "NODE DTOR\n";
	delete left;
	delete right;
	left = 0;
	right = 0;
}