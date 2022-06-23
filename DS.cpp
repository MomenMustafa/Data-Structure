#include <iostream>
#include <list>
#include "List.cpp"
using namespace std;
int main()
{
	List<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.reverse();
	while (!l.empty())
	{
		cout<<l.pop_front()<<endl;
	}
}