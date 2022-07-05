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
    bool isBST(TreeNode* root, int left, int right) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= left || root->val >= right) {
            return false;
        }
        return isBST(root->left, left, root->val) && isBST(root->right, root->val, right);
    }
    int cnt(TreeNode* root) {
        return root == nullptr ? 0 : cnt(root->left) + cnt(root->right) + 1;
    }
    int largestBSTSubtree(TreeNode* root) {
        if (isBST(root, INT_MIN, INT_MAX)) {
            return cnt(root);
        }
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};