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
struct NodeInf {
    int left;
    int right;
    int sz;
};
class Solution {
public:
    int ans = 0;
    NodeInf dfs(TreeNode* root) {
        int left = root->val, right = root->val;
        int sz = 1;
        int valid = 1;
        if (root->left) {
            NodeInf L = dfs(root->left);
            if (L.sz != -1 && root->val > L.right) {
                sz += L.sz;
                left = L.left;
            }
            else {
                valid = 0;
            }
        }
        if (root->right) {
            NodeInf R = dfs(root->right);
            if (R.sz != -1 && root->val < R.left) {
                sz += R.sz;
                right = R.right;
            }
            else {
                valid = 0;
            }
        }
        if (valid) {
            ans = max(ans, sz);
            return (NodeInf){left, right, sz};
        }
        return (NodeInf){-1, -1, -1};
    }
    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root);
        return ans;
    }
};