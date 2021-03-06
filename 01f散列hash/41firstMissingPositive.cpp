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

// 解题思路：原数组修改成hash表
// 数组大小为N，则最小missing的整数只能是[1,N+1]之间的数，可以对数组进行修改的前提下；
// 1.遍历数组，将负数的值改为N+1；
// 2.再次遍历数组，则如果出现绝对值大小在[1,N]之间的数x，则令位置**x-1**上的数为负数(因为索引从0开始)；
// 3.再次遍历该数组，如果不存在正数，说明最小的missing正数为N+1，否则第一个正数的位置就是最小missing positive；

int firstMissingPositive(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] <= 0)
        {
            nums[i] = numsSize + 1;
        }
    }

    for (int i = 0; i < numsSize; i++)
    {
        int temp = abs(nums[i]);
        if (temp > 0 && temp <= numsSize)
        {
            nums[temp - 1] = -abs(nums[temp - 1]);
        } 
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
            return i + 1;
    }

    return numsSize + 1;
}