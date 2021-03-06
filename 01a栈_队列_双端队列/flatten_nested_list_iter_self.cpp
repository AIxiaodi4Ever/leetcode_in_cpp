// ˼·����listѹ��ջ���б�ͷ��ջ������ջ��top��ʼ����
// ���ջ��Ԫ�������������ջ��top-1������NestedIntegerGetList(),NestedIntegerGetListSize()
// ��top-1��λ�ã�����ȡ���µ��б���ջ���µ��б�ͷ��ջ��
/****������һ���������б�����һ�����б�****/

/*
#include <stdio.h>
#include <stdlib.h>
*/

/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 */
 //bool NestedIntegerIsInteger(struct NestedInteger *);
 /*
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 */
 //int NestedIntegerGetInteger(struct NestedInteger *);
 /*
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 */
 //struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 /*
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 */
//int NestedIntegerGetListSize(struct NestedInteger *);

struct NestedIterator 
{
    int length;
    int top;
    struct NestedInteger **stack;
};

struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize)
{
    struct NestedIterator *iter;
    // calloc���Զ�������Ԫ�س�ʼ��Ϊ0
    iter = (struct NestedIterator *)calloc(1, sizeof(struct NestedIterator));
    iter->stack = (struct NestedInteger **)calloc(nestedListSize, sizeof(struct NestedInteger *));

    for (int i = 0; i < nestedListSize; i++)
    {
        iter->stack[i] = nestedList[nestedListSize - 1 - i];
        iter->top++;
    }
    // iter->lengthΪ��֮���ڴ����
    iter->length = nestedListSize;
    return iter;
}

bool nestedIterHasNext(struct NestedIterator *iter)
{
    int i;
    struct NestedInteger **temp_list;
    int len;

    if (iter->top <= 0)
    {
        return false;
    }
    // ���top>0����ջ������������ֽ�
    while (iter->top > 0 && !NestedIntegerIsInteger(iter->stack[iter->top - 1]))
    {
        temp_list = NestedIntegerGetList(iter->stack[iter->top - 1]);
        len = NestedIntegerGetListSize(iter->stack[iter->top - 1]);
        if (iter->length < iter->top + len)
        {
            iter->length = iter->top + len;
            iter->stack = (struct NestedInteger **)realloc(iter->stack, iter->length * sizeof(struct NestedInteger *));
            // û��������ΪNULL�ļ���
        }

        iter->top--;    // ��ջ��ֽ�������ջ
        for (i = 0; i < len; i++)
        {
            // �Ҵ�д����temp_list[len - i - i]
            iter->stack[iter->top++] = temp_list[len - 1 - i];
        }
    }

    // ��ֹ�����б���Ƕ�׿��б�����
    if (iter->top > 0) 
    {
        return true;
    }
    return false;
}

int nestedIterNext(struct NestedIterator *iter)
{
    iter->top--;
    return NestedIntegerGetInteger(iter->stack[iter->top]);
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter)
{
    free(iter->stack);
    free(iter);
}

/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */