#pragma once

template <typename T>
class Queue
{
	int capacity, size;
	int start, end;
	T* queue;
	void Expand();
public:
	Queue();
	Queue(int size);
	~Queue();
	void Push(T);
	T Back();
	T Front();
	bool IsEmpty();
	T Pop();
	int Size();
};

