#pragma once
template <typename T>
class Stack
{
	int capacity, size;
	int* stack;
	void Expand();
public:
	Stack();
	Stack(T capacity);
	~Stack();
	void Push(T val);
	T Pop();
	bool IsEmpty();
	int Size();
	T Top();
};

