/**
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
    int ans = 0;
    void count(TreeNode *root, int ma)
    {
        if (root == nullptr)
            return;
        cout << ma << endl;
        if (root->val >= ma)
            ans++;
        count(root->left, max(ma, root->val));
        count(root->right, max(ma, root->val));
    }
    int goodNodes(TreeNode *root)
    {
        count(root, root->val);

        return ans;
    }
};