#include "Queue.cpp"

int main()
{
	Queue<int> queue;
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	queue.Enqueue(50);
	queue.Enqueue(60);
	queue.Enqueue(70);
	queue.Enqueue(80);
	queue.Enqueue(90);
	queue.Enqueue(100);

	std::cout << "DQ: " << queue.Dequeue()->value << "\n";
	std::cout << "Peek 3: " << queue.Peek(2)->value << "\n"; 
	std::cout << "Front: " << queue.Front()->value << "\n"; 
	std::cout << "Back: " << queue.Back()->value << "\n"; 
	std::cout << "IsEmpty: " << queue.IsEmpty() << "\n"; 
	std::cout << "Contains 70: " << queue.Contains(70) << "\n"; 
	std::cout << "Size: " << queue.Size() << "\n";

	return 0;
}