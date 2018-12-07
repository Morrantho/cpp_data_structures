#include "LinkedList.cpp"
#include <iostream>

int main()
{
	LinkedList<int> ll;
	ll.Add(30);
	ll.Add(10);
	ll.Add(20);
	ll.Add(40);

	std::cout << ll.Contains(20) << "\n";
	std::cout << ll.Find(10)->previous->value << "\n";

	ll.Remove(10);

	for(Node<int>* p = ll.head; p != 0; p = p->next)
		std::cout << p->value << "\n";

	return 0;
}