class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i)
            dp[i] = i;
        for (int i = n - 2; i >=0; --i)
        {
            for (int j = i + 1; j < n; ++j)
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
    }
};