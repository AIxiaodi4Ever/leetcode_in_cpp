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
    TreeNode* preNode;

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        preNode->right = root;
        root->left = nullptr;
        preNode = root;

        inorder(root->right);
        return;
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummyNode = new TreeNode(-1);
        preNode = dummyNode;
        inorder(root);
        return dummyNode->right;
    }
};