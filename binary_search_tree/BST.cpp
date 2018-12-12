#include "BST.h"
#include <iostream>
#include <string>

template<typename T>
BST<T>::BST()
{
	root = 0;
}

template<typename T>
BST<T>::~BST()
{
	delete root;
	root = 0;
}

// log n
template<typename T>
Node<T>* BST<T>::Add(T value, Node<T>* n)
{
	if(root == 0)
	{
		root = new Node<T>(value);
		return root;
	}
	else if(n->value > value && n->left == 0)
	{
		n->left = new Node<T>(value);
		n->left->parent = n;
		return n->left;
	}
	else if(n->value < value && n->right == 0)
	{
		n->right = new Node<T>(value);
		n->right->parent = n;
		return n->right;
	}
	else if(n->value > value && n->left != 0) return Add(value,n->left);
	else if(n->value < value && n->right != 0) return Add(value,n->right);
}

// log n
template<typename T>
Node<T>* BST<T>::Find(T value, Node<T>* n)
{
	if(n == 0) return 0;
	if(n->value == value) return n;
	else if(n->value > value ) return Find(value,n->left);
	else if(n->value < value) return Find(value, n->right);
}

// n
template<typename T>
void BST<T>::InOrder( Node<T>* n, void (*cb)(Node<T>* value) )
{
	if(n == 0) return;
	InOrder(n->left, cb);
	cb(n);
	InOrder(n->right, cb);
}

// n
template<typename T>
void BST<T>::PreOrder( Node<T>* n, void (*cb)(Node<T>* value) )
{
	if(n == 0) return;
	cb(n);
	PreOrder(n->left, cb);
	PreOrder(n->right, cb);
}

// n
template<typename T>
void BST<T>::PostOrder( Node<T>* n, void (*cb)(Node<T>* value) )
{
	if(n == 0) return;
	PostOrder(n->left, cb);
	PostOrder(n->right, cb);
	cb(n);
}

// log n
// Not worried about balancing, thats what AVLs are for.
template<typename T>
void BST<T>::Remove(T value, Node<T>* n)
{
	if(n == 0) return;

	if(n->value == root->value)
	{
		delete root;
		root = 0;
		return;
	}

	if(n->value == value)
	{
		Node<T>* parent = n->parent;
		bool isLeft = n == n->parent->left ? 1:0;
		if(isLeft) parent->left = 0;
		else parent->right = 0;
		delete n;
	}
	else if(n->value > value && n->left != 0) Remove(value, n->left);
	else if(n->value < value && n->right != 0) Remove(value, n->right);
}

// log n
template<typename T>
Node<T>* BST<T>::Min(Node<T>* n)
{
	if(n->left == 0) return n;
	return Min(n->left);
}

// log n
template<typename T>
Node<T>* BST<T>::Max(Node<T>* n)
{
	if(n->right == 0) return n;
	return Max(n->right);
}