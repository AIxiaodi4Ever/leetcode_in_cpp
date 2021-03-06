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
        stack<TreeNode *> nodes;
        vector<int> ans;
        while (root != nullptr || !nodes.empty())
        {
            while (root != nullptr)
            {
                nodes.push(root);
                root = root->left;
            }
            // 这里用了root，而不是声明一个TreeNode*
            root = nodes.top();
            nodes.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};