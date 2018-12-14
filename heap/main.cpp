#include "Heap.cpp"
#include <iostream>

int main()
{
	Heap<int,16> heap;
	heap.Insert(20);
	heap.Insert(5);
	heap.Insert(15);
	heap.Insert(3);

	for(int i=0; i < 16; i++)
		if(heap.table[i] != 0)
			std::cout << *heap.table[i] << "\n";

	return 0;
}