class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 0, ans = 0;
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i])  {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];    // 不是将cnt[i]重置为1，而是重置为cnt[j]
                    }
                    else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];   // 同样，不是累加1，而是累加cnt[j]
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                ans = cnt[i];
            }
            else if (dp[i] == maxLen) {
                ans += cnt[i];
            }
        }
        
        return ans;
    }
};