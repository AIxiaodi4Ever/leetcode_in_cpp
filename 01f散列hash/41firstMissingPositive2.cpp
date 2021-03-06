// leetcode:41
// description:
/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

Note:
Your algorithm should run in O(n) time and uses constant extra space.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 使用一个hash表的时间为O(N), 空间为O(N);
// 从数字1到N遍历的时间为O(N), 空间为O(1);
// 因此，如果不能修改数组，那么不存在时间O(N)且空间O(1)的算法；

// 解题思路：置换
// 如果[1，N]之间的数字x出现，则将它与位置x-1的数字交换，及把正数x放在位置x-1;
// 注意如果有重复的出现，则交换会一直进行，所以应该加一个判断条件；

int firstMissingPositive(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        // 必须用while而不是if，因为改变了nums[i]的值
        while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1])
        {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }

    return numsSize + 1;
}