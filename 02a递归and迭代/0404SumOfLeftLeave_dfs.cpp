/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isLeave(TreeNode *root)
    {
        return !root->left && !root->right;
    }

    int dfs(TreeNode *root)
    {
        int ans = 0;
        if (root->left)
            ans += isLeave(root->left) ? root->left->val : dfs(root->left);
        if (root->right && !isLeave(root->right))
            ans += dfs(root->right);
        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) 
    {
        return root ? dfs(root) : 0;
    }
};