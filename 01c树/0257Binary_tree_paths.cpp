// leetcode:257
#include <stdio.h>
#include <stdlib.h>

//Definition for a binary tree node.
/*struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};*/
 

void get_path(char **array, struct TreeNode* root, int* returnSize, int *buf, int local)
{
    if (root == NULL) {
        return;
    }
    if(!root->left && !root->right) {
        //说明找到路了，把缓冲区的打印出来即可
        char *str = (char*)malloc(1024);
        int len = 0;
        for (int i = 0; i < local; i++) {
            len += sprintf(str + len, "%d->", buf[i]);
        }
        sprintf(str + len, "%d", root->val);
        array[(*returnSize)++] = str;
    } else {
        // 把当前的值写进buf，层级+1，继续递归找路
        buf[local++] = root->val;
        get_path(array, root->left, returnSize, buf, local);
        get_path(array, root->right, returnSize, buf, local);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    char **ret = (char **)malloc(1024 * sizeof(char*));
    *returnSize = 0;
    int buf[1024] = {0};
    get_path(ret, root, returnSize, buf, 0);
    return ret;
}