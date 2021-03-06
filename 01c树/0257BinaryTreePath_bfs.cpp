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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> paths;
        if (root == nullptr)
            return paths;
        
        queue<TreeNode*> nodes_queue;
        queue<string> path_queue;
        nodes_queue.push(root);
        path_queue.push(to_string(root->val));
        while (!nodes_queue.empty())
        {
            TreeNode *curr = nodes_queue.front();
            string path = path_queue.front();
            nodes_queue.pop();
            path_queue.pop();
            if (curr->left == nullptr && curr->right == nullptr)
                paths.push_back(path);
            else
            {
                if (curr->left != nullptr)
                {
                    nodes_queue.push(curr->left);
                    path_queue.push(path + "->" + to_string(curr->left->val));
                }
                if (curr->right != nullptr)
                {
                    nodes_queue.push(curr->right);
                    path_queue.push(path + "->" + to_string(curr->right->val));
                }
            }
        }
        return paths;
    }
};