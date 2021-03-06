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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        int res = 0;
        while (!nodeQueue.empty())
        {
            ++res;
            int sz = nodeQueue.size();
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* tmp = nodeQueue.front();
                nodeQueue.pop();
                if (tmp->left)
                    nodeQueue.push(tmp->left);
                if (tmp->right)
                    nodeQueue.push(tmp->right);
            }
        }
        return res;
    }
};