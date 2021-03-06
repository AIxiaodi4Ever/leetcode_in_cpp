class Solution {
public:
    // ×ó±ÕÓÒ¿ª
    void reverse(vector<int>& nums, int strat, int end)
    {
        while (strat < end)
        {
            swap(nums[strat++], nums[--end]);
        }
    }

    void rotate(vector<int>& nums, int k) 
    {
        k %= nums.size();
        reverse(nums, 0, nums.size());
        reverse(nums, 0, k);
        reverse(nums, k, nums.size());
    }
};