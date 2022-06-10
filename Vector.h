#pragma once

template <typename T>
class Vector
{
	T* vector;
	int capacity, size;

	void Expand();
	void Expand(int, T);
public:
	Vector();
	Vector(int);
	~Vector();
	void Push_back(T);
	T Pop_back();
	T At(int idx);
	T Back();
	T Front();
	//Begin();  // suspended until understanding iterators
	//End();	// same as above
	//rbegin();
	//rend();
	bool Empty();
	void Clear();
	void Insert(int idx, T val);
	T erase(int idx);
	void Reverse();
	int Size();
	T& operator [] (int);
	T& operator = (T);
};