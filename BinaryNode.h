#pragma once

template<typename T>
class BinaryNode
{
public:
	BinaryNode* left, * right;
	T key;
	BinaryNode();
	BinaryNode(T key);
};

