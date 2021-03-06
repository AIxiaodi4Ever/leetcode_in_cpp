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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) 
    {
        TreeNode *curr = root;
        while (curr != nullptr)
        {
            TreeNode* prenode = nullptr;
            if (curr->right != nullptr)
            {
                prenode = curr->right;
                while (prenode->left != nullptr && prenode->left != curr)
                    prenode = prenode->left;
                if (prenode->left == curr)
                {
                    prenode->left = nullptr;
                    sum += curr->val;
                    curr->val = sum;
                    curr = curr->left;
                }
                else
                {
                    prenode->left = curr;
                    curr = curr->right;
                }
            }
            else
            {
                sum += curr->val;
                curr->val = sum;
                curr = curr->left;
            }
        }
        return root;
    }
};