class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int n = arr.size();
        // dp[i][0]表示末尾递增的湍流子序列，dp[i][1]表示末尾递减的湍流子序列
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] > arr[i - 1])
                dp[i][0] = dp[i - 1][1] + 1;
            else if (arr[i] < arr[i - 1])
                dp[i][1] = dp[i - 1][0] + 1;
        }
        // 下面错误的代码通过了测试。。
        //return max(dp[n - 1][0], dp[n - 1][1]);
        int ret = 1;
        for (int i = 0; i < n; ++i)
        {
            ret = max(ret, dp[i][0]);
            ret = max(ret, dp[i][1]);
        }
        return ret;
    }
};