#include <iostream>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "TreeNode.h"

using namespace std;

int main() {
	BinarySearchTree<int> bst;
	bst.insertNode(49);
	bst.insertNode(28);
	bst.insertNode(83);
	bst.insertNode(18);
	bst.insertNode(40);
	bst.insertNode(71);
	bst.insertNode(97);
	bst.insertNode(11);
	bst.insertNode(19);
	bst.insertNode(32);
	bst.insertNode(44);
	bst.insertNode(69);
	bst.insertNode(72);
	bst.insertNode(92);
	bst.insertNode(99);
	bst.insertNode(100);
	bst.printTree();
	cout << "In-Order Traversal: ";
	bst.inOrderTraversal();
	cout << endl;
	cout << "Pre-Order Traversal: ";
	bst.preOrderTraversal();
	cout << endl;
	cout << "Post-Order Traversal: ";
	bst.postOrderTraversal();
	cout << endl;
	cout << "Level-Order Traversal: ";
	bst.levelOrderTraversal();
	cout << endl;
	cout << "Depth: " << bst.treeDepth() << endl;
	TreeNode<int>* r = bst.getRoot();
	TreeNode<int>* found = bst.search(r, 100);
	cout << "Found " << found->data << endl;
	bst.deleteNode(99);
	bst.deleteNode(44);
	bst.deleteNode(49);
	bst.printTree();
	return 0;
}