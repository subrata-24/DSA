#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

static int idx = -1;
Node *buildTree(vector<int> &vertex)
{
    idx++;
    if (vertex[idx] == -1)
        return nullptr;

    Node *root = new Node(vertex[idx]);
    root->left = buildTree(vertex);
    root->right = buildTree(vertex);

    return root;
}

void postOrderTraversel(Node *root)
{
    if (root == nullptr)
        return;

    postOrderTraversel(root->left);
    postOrderTraversel(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<int> vertex = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(vertex);

    // Pre-order traversel = root -> left -> right
    postOrderTraversel(root);
    cout << endl;
    return 0;
}
