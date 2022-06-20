#pragma once
#include "Vector.h"

template <typename T>
class Deque
{
	int capacity, size;
	int start, end;
	T* deque;

	void expand();
	void expand(unsigned int idx, T val);
public:
	Deque();
	Deque(unsigned int size);
	~Deque();
	T at(unsigned int idx);
	T front();
	T back();
	void clear();
	bool empty();
	/*begin();
	end();
	rbegin()
	rend()*/
	T erase(unsigned int idx);
	void insert(T val, unsigned int idx);
	T& operator [] (unsigned int);
	T& operator = (T);
	T pop_back();
	T pop_front();
	void push_back(T val);
	void push_front(T val);
	unsigned int Size();
};

