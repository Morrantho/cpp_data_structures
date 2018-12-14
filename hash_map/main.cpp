#include "HashMap.cpp"
#include <string>
#include <iostream>

int main()
{
	HashMap<int> ages;
	ages.Add("Bob",33);
	ages.Add("Bill",25);
	ages.Add("Frank",60);
	ages.Add("Dan",44);
	ages.Add("Steve",62);
	ages.Add("Ralph",67);

	std::cout << ages.Get("Bob")->value << "\n";
	ages.Remove("Bob");

	return 0;
}