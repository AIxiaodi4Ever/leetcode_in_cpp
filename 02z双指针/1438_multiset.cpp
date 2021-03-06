class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        multiset<int> s;
        int n = nums.size();
        int left = 0, right = 0;
        int ans = 0;
        while (right < n)
        {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > limit)
                s.erase(s.find(nums[left++]));
            ++right;
            ans = max(ans, right - left);
        }
        return ans;
    }
};