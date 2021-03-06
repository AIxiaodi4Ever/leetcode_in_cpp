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
        my_dfs(levelOrder, 0, root);
        reverse(levelOrder.begin(), levelOrder.end());
        return levelOrder;
    }

    void my_dfs(vector<vector<int>>& levelOrder, int depth, TreeNode* node)
    {
        if (node == nullptr)
            return;
        // 当进入新的一层时，添加新的容器（关键）
        if (levelOrder.size() == depth)
            levelOrder.push_back(vector<int>());
        levelOrder[depth].push_back(node->val);
    
        my_dfs(levelOrder, depth + 1, node->left);
        my_dfs(levelOrder, depth + 1, node->right);
    }
};