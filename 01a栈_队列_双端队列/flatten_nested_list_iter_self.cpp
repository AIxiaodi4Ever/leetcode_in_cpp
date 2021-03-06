// 思路：将list压入栈，列表头在栈顶，从栈顶top开始遍历
// 如果栈顶元素是整数，则出栈，top-1。否则NestedIntegerGetList(),NestedIntegerGetListSize()
// 从top-1的位置，将获取的新的列表入栈，新的列表头在栈顶
/****最后会有一个输入是列表里有一个空列表****/

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
    // calloc会自动将所有元素初始化为0
    iter = (struct NestedIterator *)calloc(1, sizeof(struct NestedIterator));
    iter->stack = (struct NestedInteger **)calloc(nestedListSize, sizeof(struct NestedInteger *));

    for (int i = 0; i < nestedListSize; i++)
    {
        iter->stack[i] = nestedList[nestedListSize - 1 - i];
        iter->top++;
    }
    // iter->length为了之后内存分配
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
    // 如果top>0，且栈顶不是整数则分解
    while (iter->top > 0 && !NestedIntegerIsInteger(iter->stack[iter->top - 1]))
    {
        temp_list = NestedIntegerGetList(iter->stack[iter->top - 1]);
        len = NestedIntegerGetListSize(iter->stack[iter->top - 1]);
        if (iter->length < iter->top + len)
        {
            iter->length = iter->top + len;
            iter->stack = (struct NestedInteger **)realloc(iter->stack, iter->length * sizeof(struct NestedInteger *));
            // 没有做返回为NULL的检验
        }

        iter->top--;    // 出栈后分解重新入栈
        for (i = 0; i < len; i++)
        {
            // 我错写成了temp_list[len - i - i]
            iter->stack[iter->top++] = temp_list[len - 1 - i];
        }
    }

    // 防止输入列表里嵌套空列表的情况
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