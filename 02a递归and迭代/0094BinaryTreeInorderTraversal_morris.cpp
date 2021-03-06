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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        TreeNode* predecessor;
        while (root != nullptr)
        {
            // 无左子树，直接压入答案
            if (root->left == nullptr)
            {
                ans.push_back(root->val);
                root = root->right;
            }
            else
            {
                predecessor = root->left;
                // predecessor就是当前节点向左一步，然后一直向右直到无法走为止
                while (predecessor->right != nullptr && predecessor->right != root)
                    predecessor = predecessor->right;
                // 让predecessor指向root然后继续遍历左子树
                if (predecessor->right == nullptr)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树遍历完成，继续遍历右子树
                else
                {
                    predecessor->right = nullptr;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }   
        return ans; 
    }
};