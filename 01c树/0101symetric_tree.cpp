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

// ���1����������Ϊ�������ԳƵ������ǣ�һ�������Ҷ�������һ��������������
// ����ָ�룬һ�������ƶ�������һ�������ƶ���һ�������ƶ�������һ�������ƶ�
// ÿ���ƶ����ж�����ָ��ָ��Ľڵ��Ƿ���ͬ

// �����ѵݹ黻�ɵ�������һ�����д洢����ָ��ָ��Ľڵ㣬���ڵ���������
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