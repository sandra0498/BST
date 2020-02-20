#ifndef TREENODE_H
#define TREENODE_H

template<class T>
struct TreeNode
{
	TreeNode<T>* left;
	TreeNode<T>* right;
	T data;
};
#endif