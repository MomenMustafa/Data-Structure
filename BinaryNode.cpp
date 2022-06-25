#include "BinaryNode.h"

template<typename T> BinaryNode<T>::BinaryNode() {
	left = right = nullptr;
};
template<typename T> BinaryNode<T>::BinaryNode(T key) {
	this->key = key;
	left = right = nullptr;
};

