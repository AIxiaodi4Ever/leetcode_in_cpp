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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> nodes;
        nodes.push(root);
        int ans = 0;
        while (!nodes.empty())
        {
            auto node = nodes.front();
            nodes.pop();
            if (node->left)
            {
                if (isLeave(node->left))
                    ans += node->left->val;
                else
                    nodes.push(node->left);
            }
            if (node->right)
            {
                if (!isLeave(node->right))
                    nodes.push(node->right);
            }
        }
        return ans;
    }
};