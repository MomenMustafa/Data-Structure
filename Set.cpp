#include "Set.h"
#include <assert.h>


template<typename T>Set<T>::Set()
{
	root = nullptr;
	size = 0;
}
template<typename T>Set<T>::~Set()
{
	size = 0;
	clear();
	root = nullptr;
}
template<typename T> void Set<T>::insert(T key)
{
	BinaryNode* leaf = new BinaryNode(key);
	
	if (size == 0)
	{
		root = leaf;
		++size;
	}

	BinaryNode<T>* tmp = root;
	if (find(key) == nullptr)
	{
		while (tmp->left != nullptr || tmp->right != nullptr)
			if (tmp->key > key)
				tmp = tmp->left;
			else
				tmp = tmp->rigth;
	}

	if (tmp->key > key)
		tmp->left = leaf;
	else
		tmp->rigth = leaf;
	++size;
}
template<typename T> BinaryNode<T>* Set<T>::find(T key)
{
	BinaryNode<T>* node = nullptr;
	BinaryNode<T>* tmp = root;
	while (tmp->left != nullptr || tmp->right != nullptr)
		if (key < tmp->key)
			tmp = tmp->left;
		else if (key > tmp->key)
			tmp = tmp->right;
		else if (key == tmp->key) {
			node = tmp;
			break;
		}
	return node;
}
template<typename T>inline int Set<T>::Size()
{
	return size;
}
template<typename T>inline bool Set<T>::empty()
{
	return size == 0;
}
template<typename T>inline int Set<T>::count(T key)
{
	return find(key) != nullptr;
}
template<typename T>void Set<T>::clear()
{
	order(root);
	size = 0;
	root = nullptr;
}
template<typename T> void Set<T>::order(BinaryNode<T> node)
{
	if (node != nullptr)
	{
		order(node->left);
		order(node->right);
		delete node;
		node = nullptr;
	}
}
template<typename T>BinaryNode<T> Set<T>::erase(T key)
{

}
template<typename T>BinaryNode<T>* Set<T>::lower_bound(T key)
{
	return nullptr;
}
template<typename T> BinaryNode<T>* Set<T>::upper_bound(T Key)
{
	return nullptr;
}