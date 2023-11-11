#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *SearchInBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (key == root->data)
    {
        return root;
    }

    else if (key < root->data)
    {
        return SearchInBST(root->left, key);
    }
    else if (key > root->data)
    {
        return SearchInBST(root->right, key);
    }
}

Node *insertInBST(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    else if (data < root->data)
    {
        root->left = insertInBST(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertInBST(root->right, data);
    }

    return root;
}

int main()
{
    Node *root = NULL;

    root = insertInBST(root, 50);
    root = insertInBST(root, 30);
    root = insertInBST(root, 60);
    root = insertInBST(root, 10);
    root = insertInBST(root, 40);
    root = insertInBST(root, 55);
    root = insertInBST(root, 65);

    if (SearchInBST(root, 1) == NULL)
        cout << "Not found." << endl;
    else
        cout << "Node founded" << endl;

    return 0;
}