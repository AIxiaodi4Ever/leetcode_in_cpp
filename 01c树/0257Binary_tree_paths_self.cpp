// ��Ŀ������Given a binary tree, return all root-to-leaf paths.

/*#include <stdio.h>
#include <stdlib.h>*/

//Definition for a binary tree node.
/*struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};*/

// ʹ����������buf�洢·���г����һ��ֵ��ÿһ��ֵ
// ��������Ҷʱ��buf�洢��ֵ��ӡ��temp��֮��temp���Ƶ�paths
void get_paths(struct TreeNode *root, char **paths, int *buf, int depth, int *returnSize)
{
    if (root == NULL)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        char *temp = (char *)malloc(1024);
        // ��ȷ���ַ��ĳ��ȣ����ʹ��len
        int len = 0;
        for (int i = 0; i < depth; i++)
        {
            len += sprintf(temp + len, "%d->", buf[i]);
        }
        sprintf(temp + len, "%d", root->val);
        paths[(*returnSize)++] = temp;
    }
    else
    {
        buf[depth] = root->val;
        get_paths(root->left, paths, buf, depth + 1, returnSize);
        get_paths(root->right, paths, buf, depth + 1, returnSize);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    char **paths = (char **)malloc(sizeof(char *) * 1024);
    int buf[1024] = {0};
    *returnSize = 0;

    get_paths(root, paths, buf, 0, returnSize);
    return paths;
}