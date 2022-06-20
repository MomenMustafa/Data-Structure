#pragma once

template <typename T>
class List
{
	class ListNode
	{
	public:
		ListNode* next;
		T val;
	};

	ListNode *head, *tail;
public:
	List();
	~List();

};

