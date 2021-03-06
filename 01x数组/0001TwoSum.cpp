class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> my_hash;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = my_hash.find(target - nums[i]);
            if (it != my_hash.end())
                return {it->second, i};
            my_hash[nums[i]] = i;
        }
        return {};
    }
};