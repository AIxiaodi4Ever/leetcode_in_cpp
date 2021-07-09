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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* rightMost = nullptr;
        TreeNode* father = nullptr;
        while (root->left) {
            root = root->left;
        }
        while (cur != nullptr) {
            while (cur->left) {
                rightMost = cur->left;
                while (rightMost->right) {
                    rightMost = rightMost->right;
                }
                rightMost->right = cur;
                TreeNode* temp = cur->left;
                cur->left = nullptr;
                cur = temp;
                if (father) {
                    father->right = cur;
                }
            }
            father = cur;
            cur = cur->right;
        }
        return root;
    }
};