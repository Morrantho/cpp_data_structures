#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node
{
	Node<T>* next;
	Node<T>* previous;
	T value;

	Node(T value);
	~Node();
};
#endif