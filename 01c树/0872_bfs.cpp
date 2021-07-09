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
        void dfs(TreeNode* root, vector<int>& seq) {
            if (!root->left && !root->right) {
                seq.push_back(root->val);
            }

            if (root->left) {
                dfs(root->left, seq);
            }

            if (root->right) {
                dfs(root->right, seq);
            }
        }

        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            vector<int> sqe1;
            if (root1 != nullptr) {
                dfs(root1, sqe1);
            }

            vector<int> seq2;
            if (root2 != nullptr) {
                dfs(root2, seq2);
            }

            return sqe1 == seq2;
        }
    };