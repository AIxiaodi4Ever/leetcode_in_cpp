class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) 
    {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i <= T; ++i)
        {
            for (const vector<int>& clip : clips)
            {
                if (clip[0] < i && clip[1] >= i)
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
            }
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};