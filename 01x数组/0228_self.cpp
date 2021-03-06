class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        int n = nums.size();
        int left = 0, right = 0;
        vector<string> ans;
        while (left < n)
        {
            while (right + 1 < n && nums[right] + 1 == nums[right + 1])
                ++right;
            string range;
            if (left == right)
                range = to_string(nums[left]);
            else
                range = to_string(nums[left]) + "->" + to_string(nums[right]);
            ans.push_back(range);
            ++right;
            left = right;
        }
        return ans;
    }
};