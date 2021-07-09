class Solution {
public:
    // 极大值
    // 为防止加法溢出，使用INT_MAX / 2
    static constexpr int INFTY = INT_MAX / 2;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // 将颜色调整为从0开始，没涂色用-1表示
        for (int i = 0; i < m; ++i) {
            --houses[i];
        }

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, INFTY)));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (houses[i] != -1 && houses[i] != j) {
                    continue;
                }
                for (int k = 0; k < target; ++k) {
                    for (int j0 = 0; j0 < n; ++j0) {
                        if (j == j0) {
                            if (i == 0) {
                                if (k == 0) {
                                    dp[i][j][k] = 0;
                                    break;
                                }
                            }
                            else {
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                            }
                        }
                        else if (i > 0 && k > 0) {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j0][k - 1]);
                        }
                    }// j0
                    if (dp[i][j][k] != INFTY && houses[i] == -1) {
                        dp[i][j][k] += cost[i][j];
                    }
                }//k
            }//j
        }//i
        int ans = INFTY;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[m - 1][j][target - 1]);
        }
        return ans == INFTY ? -1 : ans;
    }
};