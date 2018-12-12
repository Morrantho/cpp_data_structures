#include "Node.cpp"

#ifndef BST_H
#define BST_H
template<typename T>
class BST
{
private:
	int size;
public:
	Node<T>* root;

	BST();
	~BST();

	Node<T>* Add(T value, Node<T>* n);
	Node<T>* Find(T value, Node<T>* n);
	void InOrder( Node<T>* n, void (*cb)(Node<T>* value) );
	void PreOrder( Node<T>* n, void (*cb)(Node<T>* value) );
	void PostOrder( Node<T>* n, void (*cb)(Node<T>* value) );
	void Remove(T value, Node<T>* n);
	Node<T>* Min(Node<T>* n);
	Node<T>* Max(Node<T>* n);
};
#endif