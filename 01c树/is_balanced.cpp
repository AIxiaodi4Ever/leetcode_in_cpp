/* ��Ŀ���� */
/* ����һ�ö������ĸ��ڵ㣬�жϸ����ǲ���ƽ������������ĳ������������ڵ���������������������1����ô������һ��ƽ��������� */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/* ����˼· */
// �������������ڵ���ƽ�����򷵻ظýڵ����

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