class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int ans = 1;
        int start = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] <= nums[i - 1])
                start = i;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};