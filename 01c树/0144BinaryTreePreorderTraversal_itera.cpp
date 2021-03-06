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
        vector<int> ans;
        stack<TreeNode *> stk;
        if (root == nullptr)
            return ans;
        
        TreeNode* curr = root;
        while (!stk.empty() || curr != nullptr)
        {
            while (curr != nullptr)
            {
                ans.emplace_back(curr->val);
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            curr = curr->right;
        }
        return ans;
    }
};