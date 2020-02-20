#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include <queue>
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

template<class T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;
	void insertNodeHelper(TreeNode<T>** ptr, T value);
	void preOrderHelper(TreeNode<T>* ptr) const;
	void inOrderHelper(TreeNode<T>* ptr) const;
	void postOrderHelper(TreeNode<T>* ptr) const;
	int depthHelper(TreeNode<T>* ptr) const;
	//void printTreeLevelHelper(TreeNode<T>* ptr, int indent) const;
	void printTreeHelper(TreeNode<T>* ptr, int spaces) const;
public:
	BinarySearchTree();
	void insertNode(T d);
	void deleteNode(T d);
	void preOrderTraversal() const;
	void inOrderTraversal() const;
	void postOrderTraversal() const;
	void levelOrderTraversal() const;
	TreeNode<T>* search(TreeNode<T>* ptr, T key) const;
	TreeNode<T>* getRoot() const;
	int treeDepth() const;
	//void printTreeLevel() const;
	void printTree() const;
};

#endif