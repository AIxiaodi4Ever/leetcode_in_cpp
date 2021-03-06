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
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/two-sum
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// c语言使用数组hash，由于存在负数，计算索引时使用(nums[i] + MAX_SIZE) % MAX_SIZE;
// 即把负数m放到,索引为m+2048的位置，正数的位置不变
#define MAX_SIZE 2048

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    // 一开始忘记int *
    int *hash = (int *)malloc(sizeof(int) * MAX_SIZE), *ans = (int *)malloc(sizeof(int) * 2);

    if (nums == NULL || numsSize < 2)
        return NULL;

    // 首先另数组hash记录的索引都为-1;
    // 如果使用数组hash[MAX_SIZE]直接memset(hash, -1, sizeof(hash))即可
    // 动态分配的指针则不行，此时hash只表示第一个int，MAX_SIZE也不行因为int型占据4字节
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
    // 虽然题目说每个输入有且仅有一解，但还是存在无解的情况
    free(hash);
    *returnSize = 0;
    return NULL;
}