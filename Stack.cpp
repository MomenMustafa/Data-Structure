#include "Stack.h"
#include <assert.h>

template <typename T> Stack<T>::Stack()
{
	capacity = 5;
	size = 0;
	stack = new int[5];
}

template <typename T> Stack<T>::Stack(T capacity)
{
	this->capacity = capacity;
	size = 0;
	stack = new int[capacity];
}

template< typename T> inline void Stack<T>::Push(T val)
{
	if (this->size == this->capacity)
		Expand();

	this->stack[size++] = val;
}

template<typename T> inline T Stack<T>::Pop()
{
	assert(!IsEmpty());		// TODO: replace with exception handler in future

	return stack[--size];
}

template<typename T> inline bool Stack<T>::IsEmpty()
{
	return size == 0;
}

template<typename T> inline int Stack<T>::Size()
{
	return size;
}

template<typename T> inline T Stack<T>::Top()
{
	assert(!IsEmpty());		//TODO replace with exception handler in future
	return stack[size - 1];
}

template<typename T> Stack<T>::~Stack()
{
	delete[]stack;
	stack = NULL;
}

template<typename T> void Stack<T>::Expand()
{
	int newCapacity = 2 * capacity;
	T* newStack = new T[newCapacity];
	for (int i = 0; i < capacity; i++)
		newStack[i] = stack[i];
	
	delete[] stack;
	stack = newStack;
	capacity = newCapacity;
}