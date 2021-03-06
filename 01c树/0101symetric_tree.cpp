/* leetcode:101 */
/* 
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



/*struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};*/

// 题解1：迭代，因为两个树对称的条件是，一个树的右儿子与另一个树的左儿子相等
// 两个指针，一个向左移动，则另一个向有移动，一个向右移动，则另一个向左移动
// 每次移动都判断两个指针指向的节点是否相同

// 题解而把递归换成迭代，用一个队列存储两个指针指向的节点，根节点入列两次
bool check_symmetric(struct TreeNode *p, struct TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    
    else if (p == NULL || q == NULL)
        return false;
    
    else
        return (p->val == q->val) && check_symmetric(p->left, q->right) && check_symmetric(p->right, q->left);

}

bool isSymmetric(struct TreeNode* root)
{
    return check_symmetric(root, root);
}