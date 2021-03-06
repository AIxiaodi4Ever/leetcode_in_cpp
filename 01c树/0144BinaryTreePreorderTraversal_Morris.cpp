/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        TreeNode* curr = root;
        TreeNode* prenode = nullptr;
        vector<int> ans;
        if (root == nullptr)
            return ans;
        while (curr != nullptr)
        {
            prenode = curr->left;
            if (prenode != nullptr)
            {
                while (prenode->right != nullptr && prenode->right != curr)
                    prenode = prenode->right;
                if (prenode->right == nullptr)
                {
                    ans.emplace_back(curr->val);
                    prenode->right = curr;
                    curr = curr->left;
                    continue;
                }
                else
                    prenode->right = nullptr;
            }
            else
                ans.emplace_back(curr->val);
            curr = curr->right;
        }  
        return ans;  
    }
};