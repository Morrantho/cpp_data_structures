#include "Heap.cpp"
#include <iostream>

int main()
{
	Heap<int,16> heap;
	heap.Insert(20);
	heap.Insert(5);
	heap.Insert(15);
	heap.Insert(3);

	for(int i=1; i < 16; i++) if(heap.table[i] != 0) std::cout << *heap.table[i] << "\n";

	std::cout << "Extract: " << *heap.Extract() << "\n";

	for(int i=1; i < 16; i++) if(heap.table[i] != 0) std::cout << *heap.table[i] << "\n";

	std::cout << "Extract: " << *heap.Extract() << "\n";

	for(int i=1; i < 16; i++) if(heap.table[i] != 0) std::cout << *heap.table[i] << "\n";

	std::cout << "IsEmpty?: " << heap.IsEmpty() << "\n";
	std::cout << "Contains 15?: " << heap.Contains(15) << "\n";
	std::cout << "Top: " << heap.Top() << "\n";
	std::cout << "Size: " << heap.Size() << "\n";

	return 0;
}