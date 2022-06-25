#pragma once
#include "BinaryNode.cpp"

template<typename T>
class Set
{
	BinaryNode<T> *root;
	int size;
public:
	Set();
	~Set();
	void insert(T key);
	//being();
	//end();
	BinaryNode<T>* find(T key);
	void clear();
	int count(T key);
	bool empty();
	BinaryNode<T> erase(T key);
	BinaryNode<T>* lower_bound(T key);
	BinaryNode<T>* upper_bound(T key);
	int Size();
private:
	void order(BinaryNode<T> node);
};