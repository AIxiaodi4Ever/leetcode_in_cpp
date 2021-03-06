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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        my_dfs(root, ans);
        return ans;
    }

    void my_dfs(TreeNode* root, vector<int>& ans)
    {
        if (root == nullptr)
            return;
        my_dfs(root->left, ans);
        ans.push_back(root->val);
        my_dfs(root->right, ans);
    }
};