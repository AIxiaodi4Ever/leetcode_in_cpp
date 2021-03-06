class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int n = arr.size();
        // dp[i][0]��ʾĩβ���������������У�dp[i][1]��ʾĩβ�ݼ�������������
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] > arr[i - 1])
                dp[i][0] = dp[i - 1][1] + 1;
            else if (arr[i] < arr[i - 1])
                dp[i][1] = dp[i - 1][0] + 1;
        }
        // �������Ĵ���ͨ���˲��ԡ���
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