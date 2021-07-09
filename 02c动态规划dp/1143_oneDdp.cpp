class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> dp(n + 1, 0);

        int temp, leftUp;
        for (int i = 1; i <= m; ++i) {
            char c1 = text1[i - 1];
            temp = dp[0];
            for (int j = 1; j <= n; ++j) {
                leftUp = temp;
                temp = dp[j];
                char c2 = text2[j - 1];
                if (c1 == c2) {
                    dp[j] = leftUp + 1;
                }
                else {
                    dp[j] = max(dp[j - 1], dp[j]);
                }
            }
        }

        return dp[n];
    }
};