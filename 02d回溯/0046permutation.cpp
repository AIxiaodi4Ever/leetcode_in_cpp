// leetcode:46
/*
��Ŀ������
Given a collection of distinct integers, return all possible permutations.
���ӣ�
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/permutations
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int *nums, int size, char *used, int *path, int pos, int **res, int *resSize, int **resColSize)
{
    int i;

    if (pos == size)
    {
        res[*resSize] = malloc(sizeof(int) * size);
        memcpy(res[*resSize], path, sizeof(int) * size);
        (*resColSize)[*resSize] = size;
        *resSize = *resSize + 1;

        return;
    }

    for (i = 0; i < size; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            path[pos] = nums[i];
            dfs(nums, size, used, path, pos + 1, res, resSize, resColSize);
            used[i] = 0;
        }
    }
}

int** permute(int* nums, int size, int* resSize, int** resColSize){
    int i;
    int **res = NULL;
    int path[size];
    char used[size];

    /* ������� */
    *resSize = 1;
    for (i = 2; i <= size; i++)
        *resSize = *resSize * i;
    
    /* ����ռ� */
    res = malloc(*resSize * sizeof(int *));
    *resColSize = malloc(*resSize * sizeof(int));

    for (i = 0; i < size; i++)
    {
        used[i] = 0;
    }
    *resSize = 0;

    dfs(nums, size, used, path, 0, res, resSize, resColSize);
      
    return res;
}

/*
���ߣ�tpcode-2
���ӣ�https://leetcode-cn.com/problems/permutations/solution/shen-du-you-xian-hui-su-by-tpcode-2/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
