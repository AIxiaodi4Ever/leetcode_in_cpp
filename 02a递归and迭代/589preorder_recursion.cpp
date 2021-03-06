// leetcode:589 ǰ�����n����
// �ݹ�ʵ��

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

#define MAX 10001

// �������û���ָ���޸�index
void pre_traversal(int *ret, int *index, struct Node* curPos)
{
    if (curPos == NULL)
        return;
    ret[(*index)++] = curPos->val;
    for (int i = 0; i < curPos->numChildren; i++)
    {
        pre_traversal(ret, index, curPos->children[i]);
    }
}

int* preorder(struct Node* root, int* returnSize) 
{
    int *ret = (int *)malloc(sizeof(int) * MAX);
    int index = 0;
    pre_traversal(ret, &index, root);
    *returnSize = index;
    return ret;
}