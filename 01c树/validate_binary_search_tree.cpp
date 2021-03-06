/* 题目描述：
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* 解题思路：DFS，递归，先给定一个无穷区间(-inf,inf)，调用左子树是改变inf为root.val，调用右子树时改变-inf为root.val */
/* 如果左子树的数值不在对应的*开区间*内，则返回false，否则返回true */

bool helper(struct TreeNode* root, long long lower, long long upeer)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->val <= lower || root->val >= upeer)
    {
        return false;
    }
    else
    {
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upeer);
    }
}

bool isValidBST(struct TreeNode* root)
{
    return helper(root, -__LONG_MAX__, __LONG_MAX__);
}