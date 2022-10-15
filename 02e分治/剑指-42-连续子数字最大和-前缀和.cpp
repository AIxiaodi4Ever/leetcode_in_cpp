class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> preSum(n + 1, 0);
        int minValue = 0, maxSum = -100;
        for (int i = 1; i <= n; ++i) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            maxSum = max(maxSum, preSum[i] - minValue);
            minValue = min(minValue, preSum[i]);
        }
        return maxSum;
    }
};