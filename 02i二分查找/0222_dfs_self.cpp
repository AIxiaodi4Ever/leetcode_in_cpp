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
    int ans = 0;
    int countNodes(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        ++ans;
        countNodes(root->left);
        countNodes(root->right);
        return ans;
    }
};