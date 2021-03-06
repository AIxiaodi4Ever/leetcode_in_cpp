// 题目描述：Given a binary tree, return all root-to-leaf paths.

/*#include <stdio.h>
#include <stdlib.h>*/

//Definition for a binary tree node.
/*struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};*/

// 使用整型数组buf存储路径中除最后一个值的每一个值
// 当到达树叶时将buf存储的值打印到temp，之后将temp复制到paths
void get_paths(struct TreeNode *root, char **paths, int *buf, int depth, int *returnSize)
{
    if (root == NULL)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        char *temp = (char *)malloc(1024);
        // 不确定字符的长度，因此使用len
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