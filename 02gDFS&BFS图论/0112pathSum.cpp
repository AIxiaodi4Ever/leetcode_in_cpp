/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool my_dfs(struct TreeNode *root, int sum, int totalSum)
{
    if (root == NULL)
        return false;

    totalSum += root->val;
    if (root->left == NULL && root->right == NULL)
    {
        return totalSum == sum;
    }
    else
        return my_dfs(root->left, sum, totalSum) || my_dfs(root->right, sum, totalSum);
}

bool hasPathSum(struct TreeNode* root, int sum)
{
    int totalSum = 0;
    return my_dfs(root, sum, totalSum);
}