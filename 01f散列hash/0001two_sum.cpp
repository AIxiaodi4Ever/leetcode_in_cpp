// leetcode: 0001
/* description:
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9
 * return [0, 1].
 * 
 * ��Դ�����ۣ�LeetCode��
 * ���ӣ�https://leetcode-cn.com/problems/two-sum
 * ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 * 
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// c����ʹ������hash�����ڴ��ڸ�������������ʱʹ��(nums[i] + MAX_SIZE) % MAX_SIZE;
// ���Ѹ���m�ŵ�,����Ϊm+2048��λ�ã�������λ�ò���
#define MAX_SIZE 2048

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    // һ��ʼ����int *
    int *hash = (int *)malloc(sizeof(int) * MAX_SIZE), *ans = (int *)malloc(sizeof(int) * 2);

    if (nums == NULL || numsSize < 2)
        return NULL;

    // ����������hash��¼��������Ϊ-1;
    // ���ʹ������hash[MAX_SIZE]ֱ��memset(hash, -1, sizeof(hash))����
    // ��̬�����ָ�����У���ʱhashֻ��ʾ��һ��int��MAX_SIZEҲ������Ϊint��ռ��4�ֽ�
    memset(hash, -1, sizeof(int) * MAX_SIZE);
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[(target - nums[i] + MAX_SIZE) %  MAX_SIZE] != -1)
        {
            ans[0] = hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE];
            ans[1] = i;
            *returnSize = 2;
            return ans;
        }
        hash[(nums[i] + MAX_SIZE) % MAX_SIZE] = i;
    }
    // ��Ȼ��Ŀ˵ÿ���������ҽ���һ�⣬�����Ǵ����޽�����
    free(hash);
    *returnSize = 0;
    return NULL;
}