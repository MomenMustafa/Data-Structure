#include <iostream>
#include "Queue.cpp"
int main()
{
	Queue<int>q;
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}
	std::cout << q.Pop() << std::endl;
	q.Push(9);
}
