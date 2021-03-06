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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> levelOrder;
        if (root == nullptr)
            return levelOrder;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            vector<int> currLevel;
            int size = nodes.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = nodes.front();
                nodes.pop();
                currLevel.push_back(node->val);
                if (node->left != nullptr)
                    nodes.push(node->left);
                if (node->right != nullptr)
                    nodes.push(node->right);
            }
            levelOrder.push_back(currLevel);
        }
        // 因为要求自底向上，所以reverse
        reverse(levelOrder.begin(), levelOrder.end());
        return levelOrder;
    }
};