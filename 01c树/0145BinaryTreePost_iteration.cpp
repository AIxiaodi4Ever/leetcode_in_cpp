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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<TreeNode *> nodes;
        TreeNode *prev = nullptr;
        TreeNode *curr = root->left;
        nodes.push(root);
        while (!nodes.empty())
        {
            while (curr != nullptr)
            {
                nodes.push(curr);
                curr = curr->left;
            }
            curr = nodes.top();
            nodes.pop();
            if (curr->right == nullptr || curr->right == prev)
            {
                ans.push_back(curr->val);
                prev = curr;
                curr = nullptr;
            }
            else
            {
                nodes.push(curr);
                curr = curr->right;
            }
        }
        return ans;
    }
};