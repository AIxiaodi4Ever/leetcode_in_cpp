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

/*
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
*/

// ˼·��dfs���ݣ�used��ʾ�ù������֣�ÿ�α���used���ֽ�û�ù������ַ����µ�λ��
// ���ܶ�int����ʹ��memset()

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs_backtracing(int *nums, int size, char *used, int *path, int **res, int pos, int *resSize, int **resColSize)
{
    if (pos == size)
    {
        res[*resSize] = (int *)malloc(sizeof(int) * size);
        memcpy(res[*resSize], path, sizeof(int) * size);
        (*resColSize)[*resSize] = size;
        *resSize = *resSize + 1;

        return;
    }

    else
    {
      for (int i = 0; i < size; i++)
      {
        if (!used[i])
        {
          used[i] = 1;
          path[pos] = nums[i];
          dfs_backtracing(nums, size, used, path, res, pos + 1, resSize,resColSize);
          used[i] = 0;
        }
      }
    }
}

int** permute(int* nums, int size, int* resSize, int** resColSize)
{
    int path[size];
    char used[size];
    int **res = NULL;

    *resSize = 1;
    for (int i = 2; i <= size; i++)
    {
      *resSize = *resSize * i;
    }

    res = (int **)malloc(sizeof(int *) * (*resSize));
    *resColSize = (int *)malloc(sizeof(int) * (*resSize));

    memset(used, 0, size);

    *resSize = 0;
    dfs_backtracing(nums, size, used, path, res, 0, resSize, resColSize);

    return res;
}