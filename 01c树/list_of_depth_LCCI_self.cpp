/*
��Ŀ������
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
* ����������������ĺ����ֿ�,��δ��ʡʱ�䣬free(curr)��������ʱ��
* �ӱ�׼�𰸿�������ʵ��bsf�����������������Ȼ��dsf������������һ��ָ�����飬��ͬ��ȵ�ֵ�������鲻ͬλ��
* ���������ָ�룬ָ�������ʼ������n��ָ���С�Ŀռ䣬ָ���ʼ������n��ָ��ָ����������ʹ�С�Ŀռ�
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