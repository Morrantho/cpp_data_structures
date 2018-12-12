#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node
{
	Node<T>* parent;
	Node<T>* left;
	Node<T>* right;
	int height;
	T value;

	Node(T value);
	~Node();
};
#endif