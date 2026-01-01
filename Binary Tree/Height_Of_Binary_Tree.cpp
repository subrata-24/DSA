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

int maxDepth(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftHt = maxDepth(root->left);
    int rightHt = maxDepth(root->right);

    return max(leftHt, rightHt) + 1;
}

int main()
{
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preOrder);

    cout << maxDepth(root) << endl;
    return 0;
}
