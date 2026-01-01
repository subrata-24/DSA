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
    unordered_map<long long int, int> mp;
    int ans = 0;
    void check(TreeNode *root, int target, long long int sum)
    {
        if (root == nullptr)
            return;
        sum += root->val;
        ans += mp[sum - target];
        mp[sum]++;
        check(root->left, target, sum);
        check(root->right, target, sum);
        mp[sum]--;
        sum -= root->val;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        long long int sum = 0;
        mp[0]++;
        check(root, targetSum, sum);
        return ans;
    }
};