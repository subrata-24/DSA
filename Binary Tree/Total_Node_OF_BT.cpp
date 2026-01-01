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
Node *buildTree(vector<int> preOrder)
{
    idx++;
    if (preOrder[idx] == -1)
        return nullptr;

    Node *root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

int totalNode(Node *root)
{
    if (root == nullptr)
        return 0;
    int totalLeftNode = totalNode(root->left);
    int totalRightNode = totalNode(root->right);

    return (totalLeftNode + totalRightNode) + 1;
}

int main()
{
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preOrder);

    cout << totalNode(root) << endl;
    return 0;
}
