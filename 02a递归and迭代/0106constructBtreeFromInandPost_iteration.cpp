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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (postorder.size() == 0)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        stack<TreeNode *> s;
        s.push(root);
        int inorderIndex = inorder.size() - 1;
        for (int i = int(postorder.size()) - 2; i >= 0; --i)
        {
            int postorderVal = postorder[i];
            TreeNode* node = s.top();
            if (node->val != inorder[inorderIndex])
            {
                node->right = new TreeNode(postorderVal);
                s.push(node->right);
            }
            else
            {
                while (!s.empty() && s.top()->val == inorder[inorderIndex])
                {
                    node = s.top();
                    s.pop();
                    --inorderIndex;
                }
                node->left = new TreeNode(postorderVal);
                s.push(node->left);
            }
        }
        return root;
    }
};