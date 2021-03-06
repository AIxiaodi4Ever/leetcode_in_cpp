class Solution {
public:
    int uniquePaths(int m, int n) {
        // 直接写出第一行的所有值
        // dp[0]=1,可以认为是除了左上的第一列所有元素
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
                dp[j] += dp[j - 1];
        }
        return dp[n - 1];
    }
};