// 贪心 二分 动态规划
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        if (envelopes.empty())
            return 0;

        sort(envelopes.begin(), envelopes.end(), [](auto &left, auto& right)->bool{
            return left[0] == right[0] ? left[1] > right[1] : left[0] < right[0];
        });

        int n = envelopes.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};  