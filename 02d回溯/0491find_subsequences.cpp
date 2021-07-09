/* leetcode:491 */
// ��Ŀ����
/* 
Given an integer array, your task is to find all the different possible increasing subsequences
of the given array, and the length of an increasing subsequence should be at least 2.

Example:

Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

Note:

    The length of the given array will not exceed 15.
    The range of integer in the given array is [-100,100].
    The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/increasing-subsequences
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// ����˼·�����������ÿһ��Ԫ�أ��ж��Ƿ������temp��ֻ�е����ڵ���ʱ�Ž������
// Ϊ�������ظ��������ǰԪ�ص���temp�����һ��Ԫ�أ���ô���뽫�����temp�����������ظ�������

#define MAX_SIZE 100000

int **ret_array = NULL;             // �������е������е�����
int *ret_column_size = NULL;        // ����ÿһ���������г��ȵ�����   
int *temp = NULL;                   // ���浱ǰ�������е�����

// ���ȫ�ֱ���ֻ����findsubsequences�����ʼ���������ύʱ�����
int ret_array_index;                // ���浱ǰ�������и���

void dfs(int *nums, int numsSize, int index,int nums_index)
{
    // ���������������
    if (nums_index == numsSize)
    {
        // ��ʱ����temp�ĳ��ȴ���2����д��ret_array
        if (index + 1 >= 2)
        {
            ret_array[ret_array_index] = (int *)malloc(sizeof(int) * (index + 1));
            for (int i = 0; i < index + 1; i++)
            {
                ret_array[ret_array_index][i] = temp[i];
            }
            ret_column_size[ret_array_index] = index + 1;
            ret_array_index++;
        }
        return;
    }

    // ����ʱ�����������
    if(nums[nums_index] > temp[index])
    {
        // ����
        temp[index + 1] = nums[nums_index];
        dfs(nums, numsSize, index + 1, nums_index + 1);

        // ������
        dfs(nums, numsSize, index, nums_index + 1);
    }

    // ����ʱ�������
    else if (nums[nums_index] == temp[index])
    {
        temp[index + 1] = nums[nums_index];
        dfs(nums, numsSize, index + 1, nums_index + 1);
    }

    // С��ʱ�޷����룬�ж�nums�е���һ��Ԫ��
    else
    {
        dfs(nums, numsSize, index, nums_index + 1);
    }
}

int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // �������
    if (numsSize <2)
    {
        *returnSize = 0;
        return NULL;
    }

    // ��ʼ��
    ret_array_index = 0;
    temp = (int *)malloc(sizeof(int) * numsSize);
    ret_array = (int **)malloc(sizeof(int *) * MAX_SIZE);
    ret_column_size = (int *)malloc(sizeof(int) * MAX_SIZE);

    // ʹnums�е�i��Ԫ����Ϊ��һ������������ǰi-1��Ԫ�ض�������temp��ѡ��
    for (int i = 0; i < numsSize - 1; i++)
    {
        temp[0] = nums[i];
        // ��֮���Ԫ�ؿ�ʼ�ݹ�
        dfs(nums, numsSize, 0, i + 1);
    }

    //����ÿһ�еĳ�����������е�����
    *returnColumnSizes = ret_column_size;
    *returnSize = ret_array_index;

    return ret_array;
}
