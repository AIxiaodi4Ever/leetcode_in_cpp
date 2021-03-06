class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
        int ans = 1;
        int temp = 1;
        int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] >  nums[i - 1])
                ++temp;
            else
            {
                ans = max(ans, temp);
                temp = 1;
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};