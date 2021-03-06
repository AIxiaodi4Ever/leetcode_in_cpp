// leetcode:343
/*
Given a positive integer n, break it into the sum of at least two positive integers 
and maximize the product of those integers. Return the maximum product you can get.

Example 1:
Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

Note: You may assume that n is not less than 2 and not larger than 58.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
动态规划解法看了半天，感觉最后的题解说的不够清楚，优化的部分我补充了点内容，题解的具体思路如下:
	? 1.dp[i]表示将i拆成n(n>=2)个数后相乘结果的最大值，dp[2]作为边界条件,dp[2] = 1。
	? 当i>2时，设可以将i拆成j + (i-j)，则dp[i]的值为下面两种情况的最大值：
	? dp[i]=max?(j ?[i?j], j ?dp[i ?j])；
	? 因此简单的方法可以对每一个i，遍历j = [1,i-1]的每一个值，最后返回dp[n]即为所求最大值。
此时时间复杂度为O(N^2)，空间复杂度为O(N)。

可以使用数学方法对动态规划进行优化，具体证明思路如下：
? 1.首先考虑j ?dp[i ?j]。
? (1)当j≥4时，可以将j拆成j/2 向上和向下取整的两个数的积，该积一定大于等于j，且等号只有在j=4时成立;
? (2)由此可知，当j≥4时dp[j]≥j，进一步可知dp[i]≥dp[j]?dp[i?j]；又因为dp[i]≥2 ?dp[i?2]≥2 ?(2 ?dp[i ?4]≥4 ?dp[i?4]；
? (3)由上面的不等式可知，j取2时，2 * dp[i ? 2]的值一定不比j取4时小，因此计算j ?dp[i ?j]时j≥4可以不用考虑;
? (4)又因为当i≥3时，dp[i?1]拆分的任何数+1后其和为i，且其积一定大于dp[i?1]，因此不用考虑dp[i]=1?dp[i?1]，即j=1。
? (5)综上所述，计算j?dp[i?j]时仅需要考虑，j=2及j=3两种情况。
? *************************************************************************************************************************
? 2.接着考虑j ?(i ?j)。
? (1)当i?j≥4时，由第1步可知，dp[i ?j]≥i ?j，因此此时不需要考虑j ?[i ?j]的值。
? (2)当i ? j <= 4时，需要考虑j ?[i ?j]，考虑j = 1，当i=3时， dp[i]=i?1=2?dp[i?2]=2，当i≥4时，d[i]≥i>i?1，因此当j=1时，要么结果包含在第1步之中，要么不需要考虑，所以计算j?(i?j)时，j=1不需要考虑。
? (3)当j≥4时，j ?(i ?j)取最大值时，j=i/2，即i≥8，此时i?j≥4，由(1)可知，此时不需要考虑。而当i=3,4,5,6,7时，i/2 的取值范围为2，3。
? 因此综上，计算j ?[i ?j]时也仅仅需要考虑j=2和j=3两种情况。
? ************************************************************************************************************************
? 所以状态转移方程如下：
? dp[i]=max?(2 ?dp[i?2], 3 ?dp[i ?3], 2 ?(i?2), 3 ?(i ?3);
其中dp[0]=dp[1] = 0，dp[2] = 1。此时时间复杂度为O(N)，空间复杂度为O(N)。
*/

class Solution {
public:
    int integerBreak(int n) 
    {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = max(max(2 * dp[i - 2], 3 * dp[i - 3]),
                        max(2 * (i - 2), 3 * (i - 3)));
        }
        return dp[n];
    }
};