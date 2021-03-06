/*��Ŀ������Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

example:
    Input: [1,2,3,null,5,null,4]
    Output: [1, 3, 4]
    Explanation:

    1            <---
    /   \
    2     3         <---
    \     \
    5     4       <---
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// ��һ��û�����д����:p
// ����˼·��BSF��¼ÿһ������������
// ��ʹ�����������÷�������Ĵ�С
// ֮�����������ʵ��BSF��ʹ�ñ���depth��ǵ�ǰ��ȣ�����right_val��¼ÿһ������ҵ�����
// ÿ�α�����ĳһ��ȵĽڵ�ʱ�����õ�ǰ�ڵ���ֵ����������ͬ�����depth��ֵ

// ��÷��������С
void get_depth(struct TreeNode *root, int level, int *returnSize)
{
    if (root == NULL)
        return;
    
    else
    {
        // ��ȴ�0��ʼ��returnSize��1��ʼ����˱Ƚ����depth+1�Ĵ�С��ϵ
        // ÿ�μ���depth+1ʹʱ��ﵽ4ms,�ĳ�level��1��ʼ������depth+1��ʱ���ʡ��0ms
        // *returnSize = *returnSize > (depth+1) ? *returnSize : (depth+1);
        *returnSize = *returnSize > level ? *returnSize : level;
        get_depth(root->left, level + 1, returnSize);
        get_depth(root->right, level + 1, returnSize);
    }
}

// ������ұߵ�ֵ
void update_value(struct TreeNode *root, int depth, int *right_val)
{
    if (root == NULL)
        return;
    
    else 
    {
        right_val[depth] = root->val;
        update_value(root->left, depth + 1, right_val);
        update_value(root->right, depth + 1, right_val);
    }
}

int *rightSideView(struct TreeNode *root, int *returnSize)
{
    int level = 1;
    int *right_val;

    *returnSize = 0;

    // ���returnSize��ֵ
    get_depth(root, level, returnSize);

    right_val = (int *)malloc(sizeof(int) * *returnSize);

    update_value(root, 0, right_val);

    return right_val;
}