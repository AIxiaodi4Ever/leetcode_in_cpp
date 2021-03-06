// leetcode:198
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
money you can rob tonight without alerting the police.

Example:
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路
// 动态规划+滚动数组
// 只有1个房间时，dp[0] = nums[0], 2个房间时,dp[1] = max(nums[0], nums[1]);
// 房间数i大于2时，状态转移方程为：dp[i] max(dp[i - 2] + nums[i], dp[i - 1]);
// 因为dp[i]之和dp[i-1]与dp[i-2]有关，所以不需要保存全部的dp，使用滚动数组，保存i-1和i-2时的最高金额即可

#define max(a, b) ((a >= b) ? a : b)

int rob(int* nums, int numsSize)
{
    int dp[2] = {0, 0};
    int temp;

    if (numsSize == 0)
        return 0;

    dp[0] = nums[0];
    if (numsSize == 1)
        return dp[0];

    dp[1] = max(nums[0], nums[1]);

    //每次循环开始之前，dp[0]存储前i-1个房间可以偷最大值，dp[1]存储前i个房间可以偷最大值
    for (int i = 2; i < numsSize; i++)
    {
        temp = dp[1];

        // 计算第i+1个房间可以偷的最大值
        dp[1] = max(dp[0] + nums[i], dp[1]);
        dp[0] = temp;
    }

    return dp[1];
}