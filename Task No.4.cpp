#include <iostream>
#include <string>
using namespace std;
struct BSTNode
{
    int isbn;
    string title;
    BSTNode* left;
    BSTNode* right;
};
struct ListNode
{
    int isbn;
    string title;
    ListNode* next;
};
class Library
{
    BSTNode* root;

public:
    ListNode* head;
    ListNode* tail;
    Library()
    {
        root = NULL;
        head = NULL;
        tail = NULL;
    }
    BSTNode* insert(BSTNode* root, int isbn, string title)
    {
        if (root == NULL)
        {
            BSTNode* newNode = new BSTNode();
            newNode->isbn = isbn;
            newNode->title = title;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        if (isbn < root->isbn)
        {
            root->left = insert(root->left, isbn, title);
        }
        else if (isbn > root->isbn)
        {
            root->right = insert(root->right, isbn, title);
        }
        return root;
    }
    void addBook(int isbn, string title)
    {
        root = insert(root, isbn, title);
    }
    void convert(BSTNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        convert(root->left);
        ListNode* newNode = new ListNode();
        newNode->isbn = root->isbn;
        newNode->title = root->title;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        convert(root->right);
    }
    void createCatalog()
    {
        convert(root);
    }
    void printCatalog()
    {
        ListNode* temp = head;

        while (temp != NULL)
        {
            cout << temp->isbn
                << " - "
                << temp->title << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    Library lib;
    lib.addBook(105, "Data Structures");
    lib.addBook(102, "Operating Systems");
    lib.addBook(120, "Database Systems");
    lib.addBook(101, "Computer Networks");
    lib.addBook(110, "Artificial Intelligence");
    lib.createCatalog();
    cout << "Sorted Book Catalog = " << endl;
    lib.printCatalog();
    return 0;
}