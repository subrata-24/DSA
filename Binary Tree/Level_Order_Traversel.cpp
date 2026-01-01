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

void levelOrderTraversel(Node *root)
{
    queue<Node *> q;
    q.push(root);

    q.push(nullptr); // To track every level

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // Add newline after evry level
        if (curr == nullptr)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(nullptr);
                continue;
            }
            else
                break;
        }

        cout << curr->data << " ";
        if (curr->left != nullptr)
            q.push(curr->left);
        if (curr->right != nullptr)
            q.push(curr->right);
    }
}

int main()
{
    vector<int> vertex = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(vertex);

    // Pre-order traversel = root -> left -> right
    levelOrderTraversel(root);
    return 0;
}
