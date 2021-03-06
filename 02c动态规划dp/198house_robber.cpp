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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/house-robber
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·
// ��̬�滮+��������
// ֻ��1������ʱ��dp[0] = nums[0], 2������ʱ,dp[1] = max(nums[0], nums[1]);
// ������i����2ʱ��״̬ת�Ʒ���Ϊ��dp[i] max(dp[i - 2] + nums[i], dp[i - 1]);
// ��Ϊdp[i]֮��dp[i-1]��dp[i-2]�йأ����Բ���Ҫ����ȫ����dp��ʹ�ù������飬����i-1��i-2ʱ����߽���

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

    //ÿ��ѭ����ʼ֮ǰ��dp[0]�洢ǰi-1���������͵���ֵ��dp[1]�洢ǰi���������͵���ֵ
    for (int i = 2; i < numsSize; i++)
    {
        temp = dp[1];

        // �����i+1���������͵�����ֵ
        dp[1] = max(dp[0] + nums[i], dp[1]);
        dp[0] = temp;
    }

    return dp[1];
}