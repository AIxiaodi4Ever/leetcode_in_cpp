class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; ++i)
            preSum[i + 1] = preSum[i] + nums[i];
        for (int i = 0; i < n; ++i)
        {
            if (preSum[i] == preSum[n] - preSum[i] - nums[i])
                return i;
        }
        return -1;
    }
};