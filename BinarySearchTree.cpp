#include "BinarySearchTree.h"
#include "TreeNode.h"



template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template<class T>
void BinarySearchTree<T>::insertNode(T d)
{
	//be mindful of different cases 
	//best case is if node has no children 
	// 1. if node has one child 
	//2. if node has two children 

	TreeNode<T>* newNode = new TreeNode<T>();
	newNode->data = d;
	if (root == NULL)
	{
		//if BST is empty : make the node the root 
		root = newNode;
	}

	else
	{
		TreeNode<T>** ptr = &root;
		//if not empty -> call on the helper 
		insertNodeHelper(ptr, d);
	}


}

template<class T>
void BinarySearchTree<T>::deleteNode(T d)
{
	TreeNode<T>* ptr = search(root, d);
	TreeNode<T>* leftChild = ptr->left;
	TreeNode<T>* rightChild = ptr->right;

	TreeNode<T>* current = root;
	TreeNode<T>* temp = NULL;


	if (ptr != NULL)
	{
		//CASE:  if ptr has no children 

		if (leftChild != NULL  && rightChild != NULL)
		{
			if (root == ptr)
			{
				delete root;
				root = NULL;
			}
		}


		if (leftChild != NULL && rightChild == NULL)
		{
			while (current != NULL)
			{
				if (current->left != NULL)
				{
					if (current->left->data == d)
					{
						current->left = ptr->left;
						delete ptr;
						ptr = NULL;
						break;
					}
				}

				if (current->right != NULL)
				{
					if (current->right->data == d)
					{
						current->right = ptr->right;
						delete ptr;
						ptr = NULL;
						break;
					}
				}

				if (current->data < d)
				{
					current = current->right;
				}

				else
				{
					current = current->left;
				}
			}
		}

		else if (leftChild == NULL && rightChild != NULL)
		{
			while (current != NULL)
			{
				if (current->left != NULL)
				{
					if (current->left->data == d)
					{
						current->left = ptr->left;
						delete ptr;
						ptr = NULL;
						break;
					}
				}

				if (current->right != NULL)
				{
					if (current->right->data == d)
					{
						current->right = ptr->right;
						delete ptr;
						ptr = NULL;
						break;
					}
				}

				if (current->data < d)
				{
					current = current->right;
				}

				else
				{
					current = current->left;
				}
			}

		}

		else if (leftChild != NULL && rightChild != NULL)
		{

			while (rightChild->left != NULL)
			{
				rightChild = rightChild->left;
				
			}

			ptr->data = rightChild->data;
			rightChild->data = d;

			current = ptr;
			current = current->right;

			while (current != NULL && current->left != NULL)
			{
				if (current->left->data == d)
				{
					if (current->left->right != NULL)
					{
						temp = current->left->right;
						delete current->left;
						current->left = temp;
						break;
					}

					else
					{
						delete current->left;
						current->left = NULL;
						break;
					}
				}

				else
				{
					current = current->right;
				}

			}
		}


	}

	current = root;
	while (current != NULL)
	{
		if (current->left != NULL)
		{
			if (current->left->data == d)
			{
				delete current->left;
				current->left = NULL;
				break;
			}
		}

		if (current->right != NULL)
		{
			if (current->right->data == d)
			{
				delete current->right;
				current->right = NULL;
				break;
			}

		}

		if (current->data < d)
		{
			current = current->right;
		}

		else
		{
			current = current->left;
		}

	}
}

template<class T>
void BinarySearchTree<T>::preOrderTraversal() const
{
	preOrderHelper(root);
}

template<class T>
void BinarySearchTree<T>::inOrderTraversal() const
{
	inOrderHelper(root);
}

template<class T>
void BinarySearchTree<T>::postOrderTraversal() const
{
	postOrderHelper(root);
}

template<class T>
void BinarySearchTree<T>::levelOrderTraversal() const
{
	for (int i = 0; i < treeDepth(); i++)
	{
		printTreeHelper(root, i);
	}


}

template<class T>
TreeNode<T>* BinarySearchTree<T>::search(TreeNode<T>* ptr, T key) const
{
	if (ptr == NULL)
	{
		return NULL;
	}


	if (ptr->data == key)
	{
		//if found 
		return ptr;
	}

	else if (ptr->data < key)
	{
		//if the key is greater than the ptr
		return search(ptr->right, key);
	}

	else
	{
		//if the key is less than the ptr 
		return search(ptr->left, key);
	}
}

template<class T>
TreeNode<T>* BinarySearchTree<T>::getRoot() const
{
	return root;
}

template<class T>
int BinarySearchTree<T>::treeDepth() const
{
	return depthHelper(root);
}

template<class T>
void BinarySearchTree<T>::printTree() const
{
	//pre order traversal 
	//calls on the helper method 
	printTreeHelper(root, 0);
}


template<class T>
void BinarySearchTree<T>::insertNodeHelper(TreeNode<T>** ptr, T value)
{
	TreeNode<T>* pointer = *ptr;
	TreeNode<T>* newNode = new TreeNode<T>();
	newNode->data = value;


	if (*ptr == NULL)
	{
		//if it is found -> set the pointer to the newNode 
		*ptr = newNode;
	}

	else if (pointer->data > value)
	{
		//if the value is smaller -> go to the left 
		ptr = &pointer->left;
		insertNodeHelper(ptr, value);
	
	}

	else if (pointer->data < value)
	{
		//if the value is larger, go to the right 
		ptr = &pointer->right;
		insertNodeHelper(ptr, value);

	}

}

template<class T>
void BinarySearchTree<T>::preOrderHelper(TreeNode<T>* ptr) const
{
	// root -> left -> right 
	if (ptr != NULL)
	{
		cout << ptr->data << " ";
		preOrderHelper(ptr->left);
		preOrderHelper(ptr->right);
	}
}

template<class T>
void BinarySearchTree<T>::inOrderHelper(TreeNode<T>* ptr) const
{
	//left - root - right 
	if (ptr != NULL)
	{
		inOrderHelper(ptr->left);
		cout << ptr->data << " ";
		inOrderHelper(ptr->right);
	}
}

template<class T>
void BinarySearchTree<T>::postOrderHelper(TreeNode<T>* ptr) const
{
	//left - right - root 
	if (ptr != NULL)
	{
		postOrderHelper(ptr->left);
		postOrderHelper(ptr->right);
		cout << ptr->data << " ";
	}
}

template<class T>
int BinarySearchTree<T>::depthHelper(TreeNode<T>* ptr) const
{
	if (ptr == NULL)
	{
		return 0;
	}

	else
	{
		int leftHeight = depthHelper(ptr->left);
		int rightHeight = depthHelper(ptr->right);

		return max(leftHeight, rightHeight) + 1; 
	}
}

template<class T>
void BinarySearchTree<T>::printTreeHelper(TreeNode<T>* ptr, int spaces) const
{
	if (ptr != NULL)
	{
		spaces += 6;

		printTreeHelper(ptr->right, spaces);
		cout << endl;

		for (int i = 0; i < spaces; i++)
		{
			cout << " "; 
		}

		cout << ptr->data << endl;

		printTreeHelper(ptr->left, spaces);

		
	}

}

