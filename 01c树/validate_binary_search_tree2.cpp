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

/* 解题思路：二叉查找树中序遍历结果必定为升序排列 */
/* stack在C中使用不了，但在C++中正确 */

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
  };

bool isValidBST(struct TreeNode* root)
{
    stack(TreeNode *) stack;
    struct TreeNode *rooter = root;
    long long inorder = (long long)INT_MIN - 1;

    while (!stack.empty() || rooter != NULL)
    {
        while (rooter != NULL)
        {
            push(rooter);
            rooter = rooter->left;
        }

        rooter = stack.top();
        stack.pop();

        if (rooter->val <= inorder)
            return false;
        inorder = rooter->val;
        rooter = rooter->right;
    }

    return true;
}