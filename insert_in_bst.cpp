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
void Print_levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();

        cout << root->data << " ";

        if (root->left != NULL)
            q.push(root->left);

        if (root->right != NULL)
            q.push(root->right);
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node *insertInBST(Node *root, int data) // Jevabei input ney O amake BST create kore dibe
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insertInBST(root->left, data);
    }
    if (data > root->data)
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

    inOrder(root);
    cout << '\n';

    Print_levelOrder(root);

    return 0;
}