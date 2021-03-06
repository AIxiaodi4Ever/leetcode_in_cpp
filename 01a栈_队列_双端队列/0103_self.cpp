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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (root == nullptr)
            return vector<vector<int>>();
        vector<vector<int>> ans;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        stack<TreeNode *> stk;
        int level = 0;
        while (!nodeQueue.empty())
        {
            int sz = nodeQueue.size();
            vector<int> temp;
            for (int i = 0; i < sz; ++i)
            {   
                TreeNode *curr = nodeQueue.front();
                nodeQueue.pop();
                temp.push_back(curr->val);
                if (level % 2 == 0)
                {
                    if (curr->left)
                        stk.push(curr->left);
                    if (curr->right)
                        stk.push(curr->right);
                }
                else
                {
                    if (curr->right)
                        stk.push(curr->right);
                    if (curr->left)
                        stk.push(curr->left);
                }
            }  
            ++level;
            ans.push_back(temp);
            while (!stk.empty())
            {
                TreeNode* next = stk.top();
                stk.pop();
                nodeQueue.push(next);
            }
        }
        return ans;
    }
};