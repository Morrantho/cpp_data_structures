#include "Node.cpp"

#ifndef QUEUE_H
#define QUEUE_H
template<typename T>
class Queue
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	Queue();
	~Queue();

	void Enqueue(T value);
	Node<T>* Dequeue();
	Node<T>* Peek(int n);
	Node<T>* Front();
	Node<T>* Back();
	bool IsEmpty();
	int Contains(T value);
	int Size();
};
#endif