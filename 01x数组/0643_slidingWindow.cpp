class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = 0;
        for (int i = 0; i < k; ++i)
            maxSum += nums[i];
        int curSum = maxSum;
        int n = nums.size();
        for (int i = k; i < n; ++i)
        {
            curSum = curSum + nums[i] - nums[i - k];
            maxSum = max(maxSum, curSum);
        }
        return static_cast<double>(maxSum) / k;
    }
};