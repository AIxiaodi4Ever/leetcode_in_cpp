/* 题目描述 */
/* 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/* 解题思路 */
// 后序遍历，如果节点是平衡数则返回该节点深度

#define MAX(a,b) ( a >= b ) ? a : b

 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

int return_depth(struct TreeNode* root)
{
    int left_depth, right_depth;
    if (root == NULL)
        return 0;   

    left_depth = return_depth(root->left);
    right_depth = return_depth(root->right);

    if (left_depth != -1 &&  right_depth != -1 && abs(left_depth - right_depth) <= 1)
        return (MAX(left_depth, right_depth) + 1);
    
    else
        return -1;
}

bool isBalanced(struct TreeNode* root)
{
    return (return_depth(root) != -1);
}