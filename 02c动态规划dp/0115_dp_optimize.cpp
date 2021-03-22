class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<unsigned> dp(n + 1);
        dp[n] = 1;
        for (auto i = m - 1; i >= 0; --i)
            for (auto j = max(n - m + i, 0); j <= n; ++j)
                if (s[i] == t[j]) dp[j] += dp[j + 1];
        return dp[0];
    }
};