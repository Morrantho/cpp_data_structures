#include "Node.cpp"

#ifndef STACK_H
#define STACK_H
template<typename T>
class Stack
{
private:
	Node<T>* tail;
	int size;
public:
	Stack();
	~Stack();
	void Push(T value);
	Node<T>* Pop();
	Node<T>* Peek(int n);
	bool IsEmpty();
	int Contains(T value);
	int Size();
};
#endif