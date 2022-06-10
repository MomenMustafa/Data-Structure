#include <iostream>
#include "Vector.cpp"

int main()
{
	Vector<int>v;
	puts(v.Empty() ? "emtpy" : "not empty");
	for (int i = 0; i < 10; i++)
	{
		v.Push_back(i);
	}
	v.Reverse();
	for (int i=0; i<v.Size();i++)
		std::cout << v[i] << ' ';
	/*for (int i = 0; i < v.Size(); i++)
		std::cout << v[i] << ' ';
	
	std::cout << std::endl<<"sz "<<v.Size() << '\n';
	int x = 1e2;
	v.Insert(4, x);
	x = v.erase(v.Size()-1);
	std::cout << std::endl<<"x "<<x << '\n';
	for (int i = 0; i < v.Size(); i++)
		std::cout << v[i] << ' ';

	v.Clear();
	puts(v.Empty() ? "emtpy" : "not empty");*/
}
