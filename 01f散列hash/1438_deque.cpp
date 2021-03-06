class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        deque<int> queMin, queMax;
        int left = 0, right = 0;
        int ans = 0;
        int n = nums.size();
        while (right < n)
        {
            while (!queMax.empty() && queMax.back() < nums[right])
                queMax.pop_back();
            while (!queMin.empty() && queMin.back() > nums[right])
                queMin.pop_back();
            queMax.push_back(nums[right]);
            queMin.push_back(nums[right]);
            while (queMax.front() - queMin.front() > limit) // 官方还有一个二者不为空的判断，但实际上二者不可能为空，因为最差情况子序列长度为1，差值为0，而limit最小也是0
            {
                if (nums[left] == queMax.front())
                    queMax.pop_front();
                if (nums[left] == queMin.front())
                    queMin.pop_front();
                ++left;
            }
            ++right;
            ans = max(ans, right - left);
        }
        return ans;
    }
};