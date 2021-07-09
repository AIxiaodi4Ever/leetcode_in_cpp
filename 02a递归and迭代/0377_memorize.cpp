/* 递归记忆化搜索，避免了计算不必要的中间项，省去了判断combs[i-val] <= INT_MAX - combs[i]这一步 */
class Solution {
public:
    int dfs(vector<int>& nums, int newTarget, vector<int>& combs, vector<bool>& calculated) {
        if (calculated[newTarget]) {
            return combs[newTarget];
        }
        for (int& val : nums) {
            if (val <= newTarget) {
                combs[newTarget] += dfs(nums, newTarget - val, combs, calculated);
            }
        }
        calculated[newTarget] = true;
        return combs[newTarget];
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<bool> calculated(target + 1, false);
        vector<int> combs(target + 1, 0);
        combs[0] = 1;
        calculated[0] = true;
        for (int& val : nums) {
            if (val <= target) {
                combs[target] += dfs(nums, target - val, combs, calculated);
            }
        }
        return combs[target];
    }
};