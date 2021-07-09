class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> combs(target + 1, 0);
        combs[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int val : nums) {
                if (val <= i && combs[i - val] <= INT_MAX - combs[i]) {
                    combs[i] += combs[i - val];
                }
            }
        }
        return combs[target];
    }
};