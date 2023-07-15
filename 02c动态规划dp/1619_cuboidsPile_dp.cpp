// Maximum Height by Stacking Cuboids

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end(), [](const vector<int>&a, const vector<int>&b)->bool{
            return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
        });

        int ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][0] <= cuboids[i][0] &&
                    cuboids[j][1] <= cuboids[i][1] &&
                    cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
                ans = max(ans, dp[i]);
        }
        return ans;
    }
};