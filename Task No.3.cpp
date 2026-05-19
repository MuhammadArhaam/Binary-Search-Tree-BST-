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
	Node* getRoot() { return root; }
	bool isIdentical(Node* root1, Node* root2)
	{
		if (root1 == NULL && root2 == NULL)
		{
			return true;
		}
		else if(root1 == NULL || root2 == NULL)
		{
			return false;
		}
		else if (root1->data != root2->data)
		{
			return false;
		}
		else
		{
			return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
		}
	}
};
int main()
{
	BST bst1;
	bst1.insert(50);
	bst1.insert(30);
	bst1.insert(30);
	bst1.insert(70);
	bst1.insert(20);
	bst1.insert(40);
	bst1.insert(60);
	bst1.insert(80);
	Node* temp = bst1.getRoot();
	if (temp == NULL)
	{
		cout << "Tree is empty" << endl;
	}
	else
	{
		cout << "InOrder Traversal = ";
		bst1.InOrder(temp);

		cout << endl;
	}
	BST bst2;
	bst2.insert(50);
	bst2.insert(30);
	bst2.insert(30);
	bst2.insert(70);
	bst2.insert(20);
	bst2.insert(40);
	bst2.insert(60);
	bst2.insert(80);
	if (bst2.getRoot() == NULL)
	{
		cout << "Tree is empty" << endl;
	}
	else
	{
		cout << "InOrder Traversal = ";
		bst2.InOrder(bst2.getRoot());
		cout << endl;
	}
	// To Check Identical
	if (bst1.isIdentical(bst1.getRoot(), bst2.getRoot()))
	{
		cout << "Both BSTs are identical" << endl;
	}
	else
	{
		cout << "BSTs are NOT identical" << endl;
	}
}