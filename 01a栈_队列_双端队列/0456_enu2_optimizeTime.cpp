class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> candidate_i;
        vector<int> pmin{INT_MAX};
        for (int i = 0; i < n; ++i) {
            while (!candidate_i.empty() && nums[candidate_i.top()] <= nums[i]) {
                candidate_i.pop();
            }
            if (!candidate_i.empty() && pmin[candidate_i.top()] < nums[i]) {
                return true;
            }
            candidate_i.push(i);
            pmin.push_back(min(pmin.back(), nums[i]));
        }
        return false;
    }
};