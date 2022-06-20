#include "Deque.h"
#include <assert.h>

template <typename T> Deque<T>::Deque()
{
	capacity = 5;
	start = end = size = 0;
	deque = new T[capacity];
}
template <typename T> Deque<T>::Deque(unsigned int size)
{
	capacity = size;
	start = end = this->size = 0;
	deque = new T[capacity];
}

template <typename T> Deque<T>::~Deque()
{
	delete[]deque;
	deque = nullptr;
}

template <typename T> inline T Deque<T>::at(unsigned int idx)
{
	assert(idx < size&& idx >= 0);
	return deque[idx];
}

template <typename T> inline T Deque<T>::back()
{
	assert(!empty());
	return deque[((end - 1) % capacity + capacity) % capacity];
}

template <typename T> inline T Deque<T>::front()
{
	assert(!empty());
	return deque[start];
}

template <typename T> inline void Deque<T>::clear()
{
	start = end = size = 0;
}

template <typename T> inline bool Deque<T>::empty()
{
	return size == 0;
}

template <typename T> inline unsigned int Deque<T>::Size()
{
	return this->size;
}

template <typename T> T& Deque<T>::operator [] (unsigned int idx) {

	assert(idx < size&& idx >= 0);
	return deque[(start+idx)%capacity];
}

template <typename T> T& Deque<T>::operator = (T val) {
	return val;
}

template <typename T> T Deque<T>::pop_front()
{
	assert(!empty());

	T retValue = deque[start++];
	start %= capacity;
	--size;
	return retValue;
}

template <typename T> T Deque<T>::pop_back()
{
	assert(!empty());
	T retValue = deque[((end - 1) % capacity + capacity) % capacity];
	end = ((end - 1) % capacity + capacity) % capacity;
	--size;
	return retValue;
}

template <typename T> void Deque<T>::push_back(T val)
{
	if (size == capacity)
		expand();

	deque[end++] = val;
	end %= capacity;
	++size;
}

template <typename T> void Deque<T>::push_front(T val)
{
	if (size == capacity)
		expand();

	start = ((start - 1) % capacity + capacity) % capacity;
	deque[start] = val;
	++size;
}

template <typename T> void Deque<T>::insert(T val, unsigned int idx)
{
	assert(idx < size&& idx >= 0);

	if (size == capacity)
		expand(idx, val);
	else
	{
		for (int i = size; i > idx; i--)
		{
			deque[i] = deque[i - 1];
		}
		deque[idx] = val;
		++size;
	}
}

template <typename T> T Deque<T>::erase(unsigned int idx)
{
	assert(idx < size&&idx>=0);

	T returnVal = deque[idx];

	for (int i = idx; i < size; i++)
	{
		deque[i] = deque[i + 1];
	}
	--size;
	return returnVal;
}

template <typename T> void Deque<T>::expand()
{
	int newCapacity = 2 * capacity;
	T* newDeque = new T[newCapacity];
	for (int i = 0; i < capacity; i++)
	{
		newDeque[i] = deque[i];
	}
	delete[] deque;
	deque = newDeque;
	size = capacity;
	capacity = newCapacity;
}

template <typename T> void Deque<T>::expand(unsigned int idx, T val)
{
	int newCapacity = 2 * capacity;
	T* newDeque = new T[newCapacity];
	int i;
	for (i = 0; i < idx; i++)
	{
		newDeque[i] = deque[i];
	}
	newDeque[idx] = val;

	for (i = idx + 1; i <= capacity; i++)
	{
		newDeque[i] = deque[i - 1];
	}

	delete[] deque;
	deque = newDeque;
	size = capacity + 1;
	capacity = newCapacity;
}