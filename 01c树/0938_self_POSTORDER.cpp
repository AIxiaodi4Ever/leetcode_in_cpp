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
    void postorder(TreeNode* root, int& ans, int& low, int& high) {
        if (root == nullptr) {
            return;
        }
        if (root->val < low) {
            postorder(root->right, ans, low, high);
        }
        else if (root->val > high) {
            postorder(root->left, ans, low, high);
        }
        else {
            ans += root->val;
            postorder(root->left, ans, low, high);
            postorder(root->right, ans, low, high);
        }
        return;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        postorder(root, ans, low, high);
        return ans;
    }
};