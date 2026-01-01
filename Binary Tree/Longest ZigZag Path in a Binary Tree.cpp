Longest ZigZag Path in a Binary Tree /**
                                      * Definition for a binary tree node.
                                      * struct TreeNode {
                                      *     int val;
                                      *     TreeNode *left;
                                      *     TreeNode *right;
                                      *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
                                      *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
                                      *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                      * right(right) {}
                                      * };
                                      */
    class Solution
{
public:
    int ma = 0;
    void check(TreeNode *root, int det, int ans)
    {
        if (root == nullptr)
            return;
        ma = max(ma, ans);
        if (det == -1)
        {
            if (root->left != nullptr)
                check(root->left, 0, 1);
            if (root->right != nullptr)
                check(root->right, 1, 1);
        }
        else if (det == 0)
        {
            if (root->left != nullptr)
                check(root->left, 0, 1);
            if (root->right != nullptr)
                check(root->right, 1, ans + 1);
        }
        else
        {
            if (root->left != nullptr)
                check(root->left, 0, ans + 1);
            if (root->right != nullptr)
                check(root->right, 1, 1);
        }
    }
    int longestZigZag(TreeNode *root)
    {
        check(root, -1, 0);
        return ma;
    }
};