#include "BST.cpp"

int main()
{
	BST<int> bst;
	bst.Add(30,bst.root);
	bst.Add(10,bst.root);
	bst.Add(20,bst.root);
	bst.Add(40,bst.root);
	bst.Add(50,bst.root);

	// std::cout << bst.Find(20,bst.root) << "\n";
	// bst.InOrder(bst.root,[](Node<int>* n){ std::cout << "IN ORDER: " << n->value << "\n"; });
	// bst.PreOrder(bst.root,[](Node<int>* n){ std::cout << "PRE: " << n->value << "\n"; });
	// bst.PostOrder(bst.root,[](Node<int>* n){ std::cout << "POST: " << n->value << "\n"; });
	// bst.InOrder(bst.root,[](Node<int>* n){ std::cout << "IN ORDER: " << n->value << "\n"; });
	// bst.Remove(30,bst.root);
	// bst.InOrder(bst.root,[](Node<int>* n){ std::cout << "IN ORDER: " << n->value << "\n"; });
	// std::cout << bst.Min(bst.root)->value << "\n";
	// std::cout << bst.Max(bst.root)->value << "\n";
	return 0;
}