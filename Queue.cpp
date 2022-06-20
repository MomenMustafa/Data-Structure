#include "Queue.h"
#include<assert.h>

template <typename T> Queue<T>::Queue()
{
	start = end = size = 0;
	capacity = 5;
	queue = new T[capacity];
}

template <typename T> Queue<T>::Queue(int val)
{
	start = end = size = 0;
	capacity = val;
	queue = new T[capacity];
}

template <typename T> void Queue<T>::Push(T val)
{
	if (this->size == this->capacity)
		Expand();

	queue[end++] = val;
	end %= capacity;
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
	return queue[((end-1) % capacity + capacity) % capacity];
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
	assert(!IsEmpty());
	T front = Front();
	start = (start + 1) % capacity;
	--size;
	return front;
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