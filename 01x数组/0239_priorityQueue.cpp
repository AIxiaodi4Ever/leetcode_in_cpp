class Solution {
public:
    // time: ONlogN
    // space:N
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        priority_queue<pair<int, int>> slidingMax;
        int n = nums.size();
        for (int i = 0; i < k; ++i)
            slidingMax.emplace(nums[i], i);
        
        vector<int> ans = {slidingMax.top().first};
        for (int i = k; i < n; ++i)
        {
            slidingMax.emplace(nums[i], i);
            while (slidingMax.top().second <= i - k)
                slidingMax.pop();
            ans.push_back(slidingMax.top().first);
        }

        return ans;
    }
};