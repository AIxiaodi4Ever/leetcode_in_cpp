class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int length = nums.size();
        if (length < 2)
            return length;
        vector<int> up(length), down(length);
        up[0] = 1;
        down[0] = 1;
        for (int i = 1; i < length; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            }
            else if (nums[i] < nums[i - 1])
            {
                up[i] = up[i - 1];
                down[i] = max(down[i - 1], up[i - 1] + 1);
            }
            else
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[length - 1], down[length - 1]);
    }
};