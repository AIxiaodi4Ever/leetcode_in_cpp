// ����Ա���Խ��16-11
/*
You are building a diving board by placing a bunch of planks of wood end-to-end. 
There are two types of planks, one of length shorter and one of length longer. 
You must use exactly K planks of wood. Write a method to generate all possible 
lengths for the diving board.

return all lengths in non-decreasing order.

Example:
Input: 
shorter = 1
longer = 2
k = 3
Output:  {3,4,5,6}

Note:
    0 < shorter <= longer
    0 <= k <= 100000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/diving-board-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* divingBoard(int shorter, int longer, int k, int* returnSize)
{
    int *lengths;
    if (k == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    if (longer != shorter)
    {
        lengths = (int *)malloc(sizeof(int) * (k + 1));
        *returnSize = k + 1;

        // ͨ������gap��С����ʱ��
        lengths[0] = k * shorter;
        int gap = longer - shorter;
        for (int i = 1; i <*returnSize; i++)
        {
            //lengths[i] = i * longer + (k - i) * shorter;
            // ������һ���������ֵ����gap���ټ���ʱ�䣬��Щ���������  
            lengths[i] = lengths[i - 1] + gap;
        }

        return lengths;
    }
    else
    {
        lengths = (int *)malloc(sizeof(int));
        lengths[0] = k * shorter;
        *returnSize = 1;
        return lengths;
    }
}