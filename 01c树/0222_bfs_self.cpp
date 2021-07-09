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
    int countNodes(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        int ans = 0;
        while (!nodeQueue.empty())
        {
            TreeNode *tmp = nodeQueue.front();
            ++ans;
            nodeQueue.pop();
            if (tmp->left)
                nodeQueue.push(tmp->left);
            if (tmp->right)
                nodeQueue.push(tmp->right);
        }
        return ans;
    }
};