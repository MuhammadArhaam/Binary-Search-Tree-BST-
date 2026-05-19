#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
class BST
{
	Node* root;
public:
	BST()
	{
		root = NULL;
	}
	void insert(int value)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		if (root == NULL)
		{
			root = newNode;
			return;
		}
		else
		{
			Node* temp = root;
			while (true)
			{
				if (temp->data < value)
				{
					if (temp->right == NULL)
					{
						temp->right = newNode;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
				else if (temp->data > value)
				{
					if (temp->left == NULL)
					{
						temp->left = newNode;
						break;
					}
					else
					{
						temp = temp->left;
					}
				}
				else
				{
					cout << "Duplicate value " << value << " not inserted" << endl;
					delete newNode;
					return;
				}
			}
		}		
	}
	void InOrder(Node* root)
	{
		if (root != NULL)
		{
			InOrder(root->left);
			cout << root->data << " ";
			InOrder(root->right);
		}
	}
	void PreOrder(Node* root)
	{
		if (root != NULL)
		{
			cout << root->data << " ";
			PreOrder(root->left);
			PreOrder(root->right);
		}
	}
	void PostOrder(Node* root)
	{
		if (root != NULL)
		{
			PostOrder(root->left);
			PostOrder(root->right);
			cout << root->data << " ";
		}
	}
	Node* getRoot() { return root; }
	bool searchValue(Node* root, int target)
	{
		if (root == NULL)
		{
			return false;
		}
		else if (root->data == target)
		{
			return true;
		}
		if (root->data > target)
		{
			return searchValue(root->left, target);
		}
		else
		{
			return searchValue(root->right, target);
		}
	}
};
int main()
{
	BST bst;
	bst.insert(50);
	bst.insert(30);
	bst.insert(30);
	bst.insert(70);
	bst.insert(20);
	bst.insert(40);
	bst.insert(60);
	bst.insert(80);
	Node* temp = bst.getRoot();
	if (temp == NULL)
	{
		cout << "Tree is empty" << endl;
	}
	else
	{
		cout << "InOrder Traversal = ";
		bst.InOrder(temp);

		cout << endl;

		cout << "PreOrder Traversal = ";
		bst.PreOrder(temp);

		cout << endl;

		cout << "PostOrder Traversal = ";
		bst.PostOrder(temp);
	}
	cout << endl;
	if (bst.searchValue(temp, 50))
	{
		cout << "Target found in BST" << endl;
	}
	else
	{
		cout << "Target not found in BST" << endl;
	}
}