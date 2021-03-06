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
    int post_idx;
    unordered_map<int, int> idx_map;

    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder)
    {
        if (in_left > in_right)
            return nullptr;
        
        int root_val = postorder[post_idx];
        --post_idx;
        int root_idx = idx_map[root_val];
        TreeNode* root = new TreeNode(root_val);
        // ×¢ÒâÏÈÓÒºó×ó
        root->right = helper(root_idx + 1, in_right, inorder, postorder);
        root->left = helper(in_left, root_idx - 1, inorder, postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        post_idx = postorder.size() - 1;
        int idx = 0;
        // built value-index hasp map
        for (int &v : inorder)
            idx_map[v] = idx++;
        return helper(0, inorder.size() - 1, inorder, postorder);
    }
};