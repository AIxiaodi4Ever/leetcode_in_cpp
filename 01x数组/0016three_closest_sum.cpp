// leetcode:16
/*
description:
Given an array nums of n integers and an integer target, find three integers in nums such 
that the sum is closest to target. Return the sum of the three integers. You may assume that 
each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Constraints:
    3 <= nums.length <= 10^3
    -10^3 <= nums[i] <= 10^3
    -10^4 <= target <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路
// 类似于三数求和，数组排序后，双指针即可，如果想保留原数组，则新建一个数组保留排序后的数组
// 1. 将nums排序，之后外层循环遍历第一个数，为了保证不重复，nums[first] != nums[first - 1]或first == 0时，才进行下层遍历；
// 2. 下一层循环，另second从first+1，third从numsSize-1开始，保证second < third，然后不断计算三数和并更新ans，如果和等于target直接返回；
// 3. 如果和更接近target则更新ans，并且如果和小于ans，移动second并保证小于(等于)third且不重复，如果大于ans，则third类似；
// 4. 最后返回ans即为最接近的答案.

int my_cmp(void *i1, void *i2)
{
    return *(int *)i1 - *(int *)i2;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    int ans = nums[0] + nums[1] + nums[2];

    // 排序
    qsort(nums, numsSize, sizeof(int), my_cmp);

    // 最外层遍历第一个数
    for (int first = 0; first < numsSize; first++)
    {   
        // 保证不重复
        if (first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }

        // 内层双指针循环
        int second = first + 1, third = numsSize - 1;
        while (second < third)
        {
            int sum = nums[first] + nums[second] + nums[third];

            // 如果target相同
            if (sum == target)
            {
                return target;
            }

            // 如果该和更为接近target则更新ans
            if (abs(sum - target) < abs(ans - target))
            {
                ans = sum;
            }

            // 如果求和大于target，则移动third
            if (sum > target)
            {
                // 可能导致second == third，但并不会进入下次循环；
                third--;
                // 保证不重复
                while (second < third && nums[third] == nums[third + 1])
                {
                    third--;
                }
            }

            // 如果求和小于target，则移动second
            if (sum < target)
            {
                // 可能导致second == third，但并不会进入下次循环；
                second++;
                // 保证不重复
                while(second < third && nums[second] == nums[second - 1])
                {
                    second++;
                }
            }
        }
    }

    return ans;
}