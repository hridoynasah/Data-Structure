
// Array to BST convertion

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

void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

Node *ConvertArrayToBST(int arr[], int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    int mid = (l + r) / 2;
    Node *root = new Node(arr[mid]);

    root->left = ConvertArrayToBST(arr, l, mid - 1);

    root->right = ConvertArrayToBST(arr, mid + 1, r);

    return root;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = ConvertArrayToBST(arr, 0, n - 1);

    InOrder(root);
    cout << endl;
    Print_levelOrder(root);

    return 0;
}