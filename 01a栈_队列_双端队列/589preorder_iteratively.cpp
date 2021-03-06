// leetcode:589 前序遍历n叉树
// 栈实现非递归

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 使用栈数据结构以代替递归

#define MAX 10001

int* preorder(struct Node* root, int* returnSize) 
{
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int *ret = (int *)malloc(sizeof(int) * MAX);
    int index = 0;
    struct Node **my_stack = (struct Node **)malloc(sizeof(struct Node *) * MAX);
    int top = -1;
    my_stack[++top] = root;
    while (top >= 0)
    {
        struct Node *curPos = my_stack[top--];
        ret[index++] = curPos->val;
        for (int i = curPos->numChildren - 1; i >= 0; --i)
        {
            my_stack[++top] = curPos->children[i];
        }
    }
    // free(my_stack);
    *returnSize = index;
    return ret;
}