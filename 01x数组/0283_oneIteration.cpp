class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int mark = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i])
            {
                nums[mark] = nums[i];
                ++mark;
            }
        }    
        for (; mark < n; ++mark)
            nums[mark] = 0;
    }
};