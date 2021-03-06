class Solution {
public:
    int minPatches(vector<int>& nums, int n) 
    {
        int patchs = 0;
        long long x = 1;
        int length = nums.size(), index = 0;
        while (x <= n)
        {
            if (index < length && nums[index] <= x)
            {
                x += nums[index];
                ++index;
            }
            else
            {
                x <<= 1;
                ++patchs;
            }
        }
        return patchs;
    }
};