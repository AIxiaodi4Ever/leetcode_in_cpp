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
    int my_dfs(TreeNode* root, int Prevsum)
    {
        if (root == nullptr)
            return 0;
        int sum = Prevsum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            return sum;
        else
            return my_dfs(root->left, sum) + my_dfs(root->right, sum);
    }

    int sumNumbers(TreeNode* root) 
    {
        return my_dfs(root, 0);
    }
};