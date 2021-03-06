/*题目描述：
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

// 解题思路：nums[center]的值有两种情况，要么在第一个递增区间，要么在第二个递增区间
// 第一种情况，target大于nums[left]且小于nums[center]时修改right的值，大于nums[center]及小于nums[left]时修改left值
// 第二种情况，target大于nums[center]且小于nums[right]时修改left值，小于nums[center]及大于nums[left]时修改right值
// 最后如果找到返回center，找不到返回-1


int search(int* nums, int numsSize, int target)
{
    int left, right, center;
    left = 0;
    right = numsSize - 1;

    while (right >= left)
    {
        center = left + (right - left) / 2;
        
        // 找到则返回位置
        if (target == nums[center])
            return center;

        // center在左侧递增区间
        else if (nums[left] <= nums[center])
        {
            // >= 及 <
            if (target >= nums[left] && target < nums[center])
                right = center - 1;       
            else           
                left = center + 1;
            

        }

        // center在右侧递增区间
        else
        {
            // > 及 <=
            if (target > nums[center] && target <= nums[right])
                left = center + 1;
            else
                right = center - 1;
        }
    }

    return -1;
}