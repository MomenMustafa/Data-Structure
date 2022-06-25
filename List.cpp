#include "List.h"
#include <assert.h>

template <typename T>List<T>::List()
{
	size = 0;
	head = tail = nullptr;
}
template <typename T>List<T>::~List()
{
	clear();
	delete head, tail;
	head = tail = nullptr;
}
template <typename T>inline T List<T>::front()
{
	assert(!empty());
	return head->val;
}
template <typename T>inline T List<T>::back()
{
	assert(!empty());
	return tail->val;
}
template<typename T> inline void List<T>::push_front(T val)
{
	Node *tmp = new Node(val);
	if (size == 0)
		head = tail = tmp;
	else
	{
		tmp->next = head;
		head = tmp;
	}
	++size;
}
template<typename T> inline void List<T>::push_back(T val)
{
	Node *tmp = new Node(val);
	if (size == 0)
		head = tail = tmp;
	else
	{
		tail->next = tmp;
		tail = tmp;
	}
	++size;
}
template <typename T> inline T List<T>::pop_front()
{
	assert(!empty());

	Node *tmp = head;
	head = head->next;
	T val = tmp->val;
	delete tmp;
	--size;
	return val;
}
template <typename T> T List<T>::pop_back()
{	
	assert(!empty());

	Node *tmp = head;
	while (tmp->next != tail)
		tmp = tmp->next;

	T val = tail->val;
	delete tail;
	tail = tmp;
	tail->next = nullptr;
	--size;
	return val;
}
template<typename T> inline bool List<T>::empty()
{
	return size == 0;
}
template<typename T> void List<T>::insert(int pos, T val)
{
	assert(pos >= 0 && pos < size);

	if (pos == 0)
	{
		push_front(val);
		return;
	}
	Node *tmp = head;
	while (pos-- != 1)
		tmp = tmp->next;

	Node *newNode = new Node(val);
	newNode->next = tmp->next;
	tmp->next = newNode;
	++size;
}
template <typename T> void List<T>::erase(int idx)
{
	assert(idx >= 0 && idx < size);

	if(idx == 0)
	{
		pop_front();
		return;
	}
	else if (idx == size - 1)
	{
		pop_back();
		return;
	}

	Node* tmp = head;
	while (idx-- != 1)
		tmp = tmp->next;
	Node* deletedNode = tmp->next;
	tmp->next = deletedNode->next;
	delete deletedNode;
	--size;
}
template <typename T> void List<T>::erase(int beginIdx, int elementsCount)
{
	assert(elementsCount + beginIdx <= size);
	if (beginIdx == 0) {
		while (elementsCount--)
			pop_front();

		return;
	}

	Node* start = head;
	for (int i = 0; i < beginIdx - 1; i++)
		start = start->next;

	Node* end = start;
	for (int i = 0; i <= elementsCount; i++)
		end = end->next;

	Node* deleteingTmp = start->next;
	start->next = end;

	if (beginIdx + elementsCount == size)
		tail = start;

	while (deleteingTmp != end)
	{
		start = deleteingTmp;
		deleteingTmp = deleteingTmp->next;
		delete start;
	}
	size -= elementsCount;
}
template<typename T> inline void List<T>::assign(int size, T val)
{
	clear();
	while (size--)
		push_back(val);
}
template<typename T> void List<T>::remove(T val)
{

	Node* tmp = head;
	while ( tmp == head && tmp != nullptr && tmp->val == val)
		tmp = tmp->next ,pop_front();

	if (!size)
		return;

	Node* deleting= tmp->next;
	while (deleting != nullptr)
	{
		if (deleting->val == val) {
			tmp->next = deleting->next;
			delete deleting;
			deleting = tmp->next;
			--size;
		}
		else
			tmp = tmp->next;

		tail = tmp;
	}
}
template<typename T> void List<T>::reverse()
{
	if (size > 1) {
		Node* tmpHead = head->next->next;
		Node* first = head->next;
		Node* second = head;

		do
		{
			first->next = second;
			second = first;
			first = tmpHead;
			if(tmpHead!=nullptr)
				tmpHead = tmpHead->next;
		} while (tmpHead!=nullptr);
		tmpHead = head;
		head = tail;
		tail = tmpHead;
		head->next = second, tail->next = nullptr;
	}
}
template<typename T> inline int List<T>::Size()
{
	return size;
}
template<typename T> inline void List<T>::unique()
{
	Node* tmp = head;
	Node* deletedNode = nullptr;

	while (tmp->next!= nullptr)
	{
		if (tmp->val == tmp->next->val)
		{
			deletedNode = tmp->next;
			if (deletedNode == tail)
				tail = tmp, tail->next = nullptr;
			else
				tmp->next = tmp->next->next;

			delete deletedNode;
			--size;
		}
		else
			tmp = tmp->next;
	}
}
template<typename T> inline void List<T>::clear()
{
	while (head!=nullptr)
	{
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	tail = nullptr;
	size = 0;
}