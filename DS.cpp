#include <iostream>
#include "Vector.cpp"
#include "deque.cpp"
//#include<deque>
using namespace std;
int main()
{
	//deque<int>dq;

	Deque<int>dq;
	for (int i = 0; i < 5; i++)
	{
		dq.push_back(i);
	}
	dq.insert(10, 4);

	for (int i = 0; i < dq.Size(); i++)
	{
		cout << dq[i] << ' ';
	}
}