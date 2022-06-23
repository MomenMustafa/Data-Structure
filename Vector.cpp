#include "Vector.h"
#include<assert.h>
#include<algorithm>

template <typename T> Vector<T>::Vector()
{
	size = 0;
	capacity = 5;
	vector = new T[capacity];
}

template <typename T> Vector<T>::Vector(int size)
{
	this->capacity = size;
	this->size = 0;
	vector = new T[capacity];
}

template <typename T> Vector<T>::~Vector()
{
	delete[]vector;
	vector = nullptr;
}

template <typename T>inline T Vector<T>::At(int idx)
{
	assert(idx < size&& idx >= 0, "index out of range");
	return vector[idx];
}

template <typename T> inline T Vector<T>::Back()
{
	assert(!Empty(), "vector is empty");
	return vector[size - 1];
}

template <typename T> inline T Vector<T>::Front()
{
	assert(!Empty(), "vector is empty");
	return vector[0];
}

template <typename T> inline bool Vector<T>::Empty()
{
	return size == 0;
}

template <typename T> inline void Vector<T>::Clear()
{
	size = 0;
}

template <typename T> inline void Vector<T>::Reverse()
{
	for (int i = 0; i < size/2; i++)
	{
		std::swap(vector[i], vector[size - i - 1]);
	}
}

template <typename T> inline int Vector<T>::Size()
{
	return size;
}

template <typename T> void Vector<T>::Push_back(T val)
{
	if (size == capacity)
		Expand();

	vector[size++] = val;
}

template <typename T> T Vector<T>::Pop_back()
{
	assert(!Empty(), "vector is empty");
	T returnVal = vector[size - 1];
	--size;
	return returnVal;
}

template <typename T> void Vector<T>::Insert(int idx, T val)
{
	assert(idx < size&& idx >= 0, "index out of range");
	if (size == capacity)
		Expand(idx, val);
	else
	{
		for (int i = size; i >idx; i--)
		{
			vector[i] = vector[i - 1];
		}
		vector[idx] = val;
		++size;
	}
}

template <typename T> T Vector<T>::erase(int idx)
{
	assert(idx < size&& idx >= 0, "index out of range");

	T returnVal = vector[idx];

	for (int i = idx; i < size; i++)
	{
		vector[i] = vector[i + 1];
	}
	--size;
	return returnVal;
}

template <typename T> void Vector<T>::Expand()
{
	int newCapacity = 2 * capacity;
	T* newVector = new T[newCapacity];
	for (int i = 0; i < capacity; i++)
	{
		newVector[i] = vector[i];
	}
	delete[] vector;
	vector = newVector;
	size = capacity;
	capacity = newCapacity;
}

template <typename T> void Vector<T>::Expand(int idx, T val)
{
	int newCapacity = 2 * capacity;
	T* newVector = new T[newCapacity];
	int i;
	for ( i = 0; i < idx; i++)
	{
		newVector[i] = vector[i];
	}
	newVector[idx] = val;

	for (i = idx + 1; i <= capacity; i++)
	{
		newVector[i] = vector[i - 1];
	}

	delete[] vector;
	vector = newVector;
	size = capacity + 1;
	capacity = newCapacity;
}

template <typename T> T& Vector<T>::operator [] (int idx) {

	assert(idx < size&& idx >= 0, "index out of range");
	return vector[idx];
}

template <typename T> T& Vector<T>::operator = (T val) {
	return val;
}