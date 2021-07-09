// leetcode:718
/*
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].

Note:
    1 <= len(A), len(B) <= 1000
    0 <= A[i], B[i] < 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 尝试使用滚动数组
// 解法1：动态规划
// 如果A[i] == B[j]那么dp[i][j] = dp[i+1][j+1]+1；
// 声明dp时将行列+1并初始化为0，这样计算最后一行或最后一列dp时不需要单独考虑；

#define max(a,b) ((a > b) ? a : b)

int findLength(int* A, int ASize, int* B, int BSize)
{
    // 逐行的求解
    int dp[BSize + 1];
    int ans = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = ASize - 1; i >= 0; i--)
    {
        // 这里是BSize - 1；
        for (int j = 0; j < BSize; j++)
        {
            dp[j] = (A[i] == B[j]) ? (dp[j + 1] + 1) : 0;
            ans = max(ans, dp[j]);
        }
    }

    return ans;
}