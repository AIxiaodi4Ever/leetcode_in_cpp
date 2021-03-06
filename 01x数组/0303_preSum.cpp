class NumArray {
public:
    vector<int> preSum;

    NumArray(vector<int>& nums) 
    {
        int n = nums.size();
        preSum.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];   
        }
    }
    
    int sumRange(int i, int j) {
        return preSum[j + 1] - preSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */