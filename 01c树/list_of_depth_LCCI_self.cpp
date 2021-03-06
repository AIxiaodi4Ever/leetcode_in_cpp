/*
题目描述：
    Given a binary tree, design an algorithm which creates a linked list 
    of all the nodes at each depth (e.g., if you have a tree with depth D, 
    you'll have D linked lists). Return a array containing all the linked lists.

    Input: [1,2,3,4,5,null,7,8]

        1
        /  \ 
        2    3
        / \    \ 
        4   5    7
    /
    8

    Output: [[1],[2,3],[4,5,7],[8]]
*/

/*
#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

void get_depth(struct TreeNode *tree, int depth, int *returnSize);
void visit_tree(struct TreeNode *tree, int depth, struct ListNode **curr);
*/

/*
* 将获得深度与遍历树的函数分开,并未节省时间，free(curr)花费最多的时间
* 从标准答案看出，树实现bsf即层序遍历，本质仍然是dsf，不过保留了一个指针数组，不同深度的值进入数组不同位置
* 深入理解了指针，指针数组初始化分配n个指针大小的空间，指针初始化分配n个指针指向的数据类型大小的空间
*/

// calculate maximum depth
// 'depth' is current depth
void get_depth(struct TreeNode *tree, int depth, int *returnSize)
{
    if (tree == NULL)
    {
        return;
    }

    *returnSize = *returnSize > depth ? *returnSize : depth;

    get_depth(tree->left, depth + 1, returnSize);
    get_depth(tree->right, depth + 1, returnSize);
}

// visit tree get every level's val
void visit_tree(struct TreeNode *tree, int depth, struct ListNode **curr)
{
    if (tree == NULL)
    {
        return;
    }

    struct ListNode *temp;
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    curr[depth]->next = temp;
    temp->val = tree->val;
    temp->next = NULL;
    curr[depth] = temp;

    visit_tree(tree->left, depth + 1, curr);
    visit_tree(tree->right, depth + 1, curr);
}


struct ListNode ** listOfDepth( struct TreeNode * tree , int * returnSize )
{
/*
    if (tree == NULL)
    {
        exit(0);
    }
*/
    struct ListNode **buf, **curr;
    *returnSize = 0;
    int i;

    // get *returnSize, depth start with 1
    get_depth(tree, 1, returnSize);

    // initialize the pointer array
    buf = (struct ListNode **)malloc(sizeof(struct ListNode *) * (*returnSize));
    curr = (struct ListNode **)malloc(sizeof(struct ListNode *) * (*returnSize));
    for (i = 0; i < *returnSize; i++)
    {
        *(curr + i) = (struct ListNode *)malloc(sizeof(struct ListNode));
        buf[i] = curr[i];
        curr[i]->next = NULL;
        curr[i]->val = INT_MIN;
    }

    // get every level's val, depth start with 0
    visit_tree(tree, 0, curr);

    // delete headers
    for (i = 0; i < *returnSize; i++)
    {
        struct ListNode *temp = buf[i];
        buf[i] = buf[i]->next;
        free(temp);
    }

    // free memory of curr
    free(curr);
    return buf;
}