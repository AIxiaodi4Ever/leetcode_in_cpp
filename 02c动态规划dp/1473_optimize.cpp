class Solution {
public:
    // 极大值
    // 为防止加法溢出，使用INT_MAX / 2
    static constexpr int INFTY = INT_MAX / 2;

    using TIII = tuple<int, int, int>;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // 将颜色调整为从0开始，没涂色用-1表示
        for (int i = 0; i < m; ++i) {
            --houses[i];
        }

        // dp所有元素初始化为极大值
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, INFTY)));
        vector<vector<TIII>> best(m, vector<TIII>(target, {INFTY, -1, INFTY}));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (houses[i] != -1 && houses[i] != j) {
                    continue;
                }
                for (int k = 0; k < target; ++k) {
                    if (i == 0) {
                        if (k == 0) {
                            dp[i][j][k] = 0;
                        }
                    }
                    else {
                        dp[i][j][k] = dp[i - 1][j][k];
                        if (k > 0) {
                            // 使用best[i - 1][k - 1]直接得到dp[i][j][k]
                            auto&& [first, first_idx, second] = best[i - 1][k - 1];
                            dp[i][j][k] = min(dp[i][j][k], (j == first_idx ? second : first));
                        }
                    }

                    if (dp[i][j][k] != INFTY && houses[i] == -1) {
                        dp[i][j][k] += cost[i][j];
                    }

                    // update best[i][j] with dp[i][j][k] 
                    // best[i][k],,, not best[i][j], above is wrong
                    // two situation
                    auto&& [first, first_idx, second] = best[i][k];
                    if (dp[i][j][k] < first) {
                        second = first;
                        first = dp[i][j][k];
                        first_idx = j;
                    }
                    else if (dp[i][j][k] < second) {
                        second = dp[i][j][k];
                    }
                }//k
            }//j
        }//i
        int ans = INFTY;
        ans = get<0>(best[m - 1][target - 1]);
        /*for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[m - 1][j][target - 1]);
        }*/
        return ans == INFTY ? -1 : ans;
    }
};