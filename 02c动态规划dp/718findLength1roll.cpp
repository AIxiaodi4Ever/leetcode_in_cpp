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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����ʹ�ù�������
// �ⷨ1����̬�滮
// ���A[i] == B[j]��ôdp[i][j] = dp[i+1][j+1]+1��
// ����dpʱ������+1����ʼ��Ϊ0�������������һ�л����һ��dpʱ����Ҫ�������ǣ�

#define max(a,b) ((a > b) ? a : b)

int findLength(int* A, int ASize, int* B, int BSize)
{
    // ���е����
    int dp[BSize + 1];
    int ans = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = ASize - 1; i >= 0; i--)
    {
        // ������BSize - 1��
        for (int j = 0; j < BSize; j++)
        {
            dp[j] = (A[i] == B[j]) ? (dp[j + 1] + 1) : 0;
            ans = max(ans, dp[j]);
        }
    }

    return ans;
}