class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (mp.count(nums[i]))
            {
                ++mp[nums[i]][0];
                mp[nums[i]][2] = i;
            }
            else
            {
                mp[nums[i]] = {1, i, i};
            }
        }

        int maxFreq = 0, minLen = 0;
        for (auto& [_, vec] : mp)
        {
            if (maxFreq < vec[0])
            {
                maxFreq = vec[0];
                minLen = vec[2] - vec[1] + 1;
            }
            else if (maxFreq == vec[0])
            {
                minLen = min(minLen, vec[2] - vec[1] + 1);
            }
        }
        return minLen;
    }
};