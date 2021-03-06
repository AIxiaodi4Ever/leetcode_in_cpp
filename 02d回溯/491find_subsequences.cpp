/* leetcode:491 */
// 题目描述
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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 解题思路：遍历数组的每一个元素，判断是否将其放入temp，只有当大于等于时才将其放入
// 为了消除重复，如果当前元素等于temp的最后一个元素，那么必须将其放入temp，否则会出现重复的序列

#define MAX_SIZE 100000

int **ret_array = NULL;             // 保存所有递增序列的数组
int *ret_column_size = NULL;        // 保存每一个递增序列长度的数组   
int *temp = NULL;                   // 保存当前递增序列的数组

// 这个全局变量只能在findsubsequences里面初始化，否则提交时会出错
int ret_array_index;                // 保存当前递增序列个数

void dfs(int *nums, int numsSize, int index,int nums_index)
{
    // 整个数组遍历结束
    if (nums_index == numsSize)
    {
        // 此时，若temp的长度大于2，则写入ret_array
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

    // 大于时考虑两种情况
    if(nums[nums_index] > temp[index])
    {
        // 放入
        temp[index + 1] = nums[nums_index];
        dfs(nums, numsSize, index + 1, nums_index + 1);

        // 不放入
        dfs(nums, numsSize, index, nums_index + 1);
    }

    // 等于时必须放入
    else if (nums[nums_index] == temp[index])
    {
        temp[index + 1] = nums[nums_index];
        dfs(nums, numsSize, index + 1, nums_index + 1);
    }

    // 小于时无法放入，判断nums中的下一个元素
    else
    {
        dfs(nums, numsSize, index, nums_index + 1);
    }
}

int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // 特殊情况
    if (numsSize <2)
    {
        *returnSize = 0;
        return NULL;
    }

    // 初始化
    ret_array_index = 0;
    temp = (int *)malloc(sizeof(int) * numsSize);
    ret_array = (int **)malloc(sizeof(int *) * MAX_SIZE);
    ret_column_size = (int *)malloc(sizeof(int) * MAX_SIZE);

    // 使nums中第i个元素作为第一个，即做出了前i-1个元素都不放入temp的选择
    for (int i = 0; i < numsSize - 1; i++)
    {
        temp[0] = nums[i];
        // 从之后的元素开始递归
        dfs(nums, numsSize, 0, i + 1);
    }

    //保存每一列的长度与递增序列的总数
    *returnColumnSizes = ret_column_size;
    *returnSize = ret_array_index;

    return ret_array;
}
