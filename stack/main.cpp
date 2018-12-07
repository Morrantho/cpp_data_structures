#include "Stack.cpp"
#include <iostream>

int main()
{
	Stack<int> stack;
	stack.Push(20);
	stack.Push(30);
	stack.Push(10);
	stack.Push(40);

	Node<int>* n = stack.Pop();
	std::cout << "Popped: " << n->value << "\n";
	delete n;

	std::cout << "IsEmpty?: " << stack.IsEmpty() << "\n"; 
	std::cout << "Size: " << stack.Size() << "\n"; 
	std::cout << "Contains 30?: " << stack.Contains(30) << "\n";
	std::cout << "Peek 3rd item: " << stack.Peek(2)->value << "\n";

	return 0;
}