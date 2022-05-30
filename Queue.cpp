#include "Queue.h"
#include<assert.h>

template <typename T> Queue<T>::Queue()
{
	size = 0;
	start = end = -1;
	capacity = 5;
	queue = new T[capacity];
}

template <typename T> Queue<T>::Queue(int val)
{
	size = 0;
	start = end = -1;
	capacity = val;
	queue = new T[capacity];
}

template <typename T> void Queue<T>::Push(T val)
{
	if (this->size == this->capacity)
		Expand();

	if (start == -1)
		start = end = 0;

	if (end == capacity)
		end = 0;

	queue[end++] = val;
	++size;
}

template<typename T> inline T Queue<T>::Front()
{
	assert(!IsEmpty());
	return queue[start];
}

template<typename T> inline T Queue<T>::Back()
{
	assert(!IsEmpty());
	if (end == 0)
		return queue[capacity - 1];

	return queue[end - 1];
}

template<typename T> inline bool Queue<T>::IsEmpty()
{
	return size == 0;
}

template<typename T> inline int Queue<T>::Size()
{
	return size;
}

template<typename T> inline T Queue<T>::Pop()
{
	T fornt = Front();

	assert(!IsEmpty());
	if (size == 1)
		start = end = -1;
	--size;
	return queue[(start++) % capacity];
}

template<typename T> Queue<T>::~Queue()
{
	delete[] queue;
	queue = NULL;
}

template<typename T> void Queue<T>::Expand()
{
	int newCapacity = 2 * capacity;
	T* newQueue = new T[newCapacity];
	for (int  i = 0; i < capacity; i++)
	{
		newQueue[i] = queue[i];
	}
	delete[] queue;
	queue = newQueue;
	end = capacity;
	capacity = newCapacity;
	start = 0;
}