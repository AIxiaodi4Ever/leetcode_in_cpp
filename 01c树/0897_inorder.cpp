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
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
        return;
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);

        TreeNode* dummyPtr = new TreeNode(-1);
        TreeNode* cur = dummyPtr;
        for (int &val : nums) {
            cur->right = new TreeNode(val);
            cur = cur->right;
        }
        
        return dummyPtr->right;
    }
};