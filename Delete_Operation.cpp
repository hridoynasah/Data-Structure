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
        Node *frnt = q.front();
        q.pop();

        cout << frnt->data << " ";

        if (frnt->left != NULL)
            q.push(frnt->left);

        if (frnt->right != NULL)
            q.push(frnt->right);
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

Node *insertInBST(Node *root, int data) // Jevabei input neu ei function Tomake BST create kore dibe
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
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

Node *FindSuccessor(Node *root)
{
    if (root->left == NULL)
        return root;

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key == root->data)
    {
        // Case 1 ---> Leaf Node

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        // Case 2 ---> Delete parent and connect its left child

        else if (root->left != NULL && root->right == NULL)
        {
            Node *delParent = root;
            root = root->left;
            delete (delParent);
        }

        // Case 2 ---> Delete parent and connect its right child

        else if (root->right != NULL && root->left == NULL)
        {
            Node *delParent = root;
            root = root->right;
            delete (delParent);
        }

        // Case 3 ---> Both children

        else
        {
            // Node *Successor = FindSuccessor(root);
            // Node *delParent = root;
            // root = Successor;
            // delete (root);

            Node *Successor = FindSuccessor(root->right);
            root->data = Successor->data;
            root->right = deleteNode(root->right, Successor->data);
        }
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
    // root = insertInBST(root, 40);
    root = insertInBST(root, 55);
    root = insertInBST(root, 57);
    root = insertInBST(root, 65);

    // Before deleting
    inOrder(root);
    cout << '\n';
    Print_levelOrder(root);

    deleteNode(root, 60);
    // After deletring

    cout << '\n';
    cout << '\n';
    inOrder(root);
    cout << '\n';
    Print_levelOrder(root);

    return 0;
}