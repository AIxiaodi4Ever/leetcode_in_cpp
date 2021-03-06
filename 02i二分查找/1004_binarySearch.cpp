class Solution {
public:
    int longestOnes(vector<int>& A, int K) 
    {
        int n = A.size();
        vector<int> preSum(n + 1);;
        for (int i = 1; i <= n; ++i)
        {
            preSum[i] = preSum[i - 1] + 1 - A[i - 1];
        }

        int ans = 0;
        for (int right = 1; right <= n; ++right)
        {
            // 这里形成了左闭右开区间[left, right)，left=right的情况除外
            // 因为前i个数的前缀和索引是0~i-1
            int left = lower_bound(preSum.begin(), preSum.end(), preSum[right] - K) - preSum.begin();
            ans = max(ans, right - left);
        }

        return ans;
    }
};