class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int n = arr.size();
        // dp0表示末尾递增，dp1表示末尾递减
        int dp0 = 1, dp1 = 1;
        int ret = 1;
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] < arr[i - 1])
            {
                dp1 = dp0 + 1;
                dp0 = 1;
            }
            else if (arr[i] > arr[i - 1])
            {
                dp0 = dp1 + 1;
                dp1 = 1;
            }
            else
                dp0 = dp1 = 1;

            ret = max(ret, dp0);
            ret = max(ret, dp1);
        }
        return ret;
    }
};