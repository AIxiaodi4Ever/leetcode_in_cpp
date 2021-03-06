// leetcode 112
// 官方的太简洁了，学习下

bool hasPathSum(struct TreeNode *root, int sum) {
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}
