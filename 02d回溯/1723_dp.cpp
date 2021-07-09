class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        int totalState = 1 << n;
        vector<int> sum(totalState, 0);
        for (int i = 1; i < totalState; ++i) {
            int x = __builtin_ctz(i), y = i - (1 << x);
            sum[i] = sum[y] + jobs[x];
        }

        vector<vector<int>> dp(k, vector<int>(1 << n, INT_MAX));
        for (int j = 0; j < totalState; ++j) {
            dp[0][j] = sum[j];
        }

        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < totalState; ++j) {
                /*for (int j0 = 0; j0 <= j; ++j0) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j^j0], sum[j0])); 
                }*/
                // 上面的处理并没有正确的寻找j的子集，且很慢
                for (int j0 = j; j0; j0 = (j0 - 1) & j) {
                    // 因为j0是j的子集，所以j^j0 == j-j0
                    dp[i][j] = min(dp[i][j], max(dp[i-1][j^j0], sum[j0]));
                }
            }
        }
        return dp[k - 1][totalState - 1];
    }
};