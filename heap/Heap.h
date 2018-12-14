#ifndef HEAP_H
#define HEAP_H
// MINHEAP
template<typename T,int N>
class Heap
{
private:
	// T* table[N] = {nullptr};
public:
	T* table[N] = {nullptr};

	Heap();
	~Heap();
	int Size();
	void Insert(T value);
	T* Extract();
	bool Contains(T value);
	bool IsEmpty();
	T* Top();
};
#endif