class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up = 1, down = 1;
        int length = nums.size();
        if (length < 2)
            return length;
        for (int i = 1; i < length; ++i)
        {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
        }
        return max(up, down);
    }
};