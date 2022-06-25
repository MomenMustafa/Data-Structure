#pragma once

template <typename T>
class List
{
	class Node
	{
	public:
		Node* next;
		T val;

		Node() { next = nullptr; };
		Node(T val) { this->val = val; next = nullptr; }
	};

	Node *head, *tail;
	int size;
public:
	List();
	~List();
	T front();
	T back();
	void push_front(T val);
	void push_back(T val);
	T pop_front();
	T pop_back();
	bool empty();
	void insert(int pos, T val);
	void erase(int idx);
	void erase(int beginIdx, int endIdx);
	void assign(int size, T val);
	void remove(T val);
	void reverse();
	int Size();
	void unique();
	void clear();
	//begin();
	//end();
	//rbegin();
	//rend();
};

