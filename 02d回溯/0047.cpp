class Solution {
public:
    vector<vector<int>> ans;

    void backTracing(vector<int>& nums, vector<bool>& vis, int depth, int &n, vector<int>& perm) {
        if (depth == n) {
            ans.push_back(perm);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.push_back(nums[i]);
            vis[i] = 1;
            backTracing(nums, vis, depth + 1, n, perm);
            perm.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        vector<int> perm;
        sort(nums.begin(), nums.end());
        backTracing(nums, vis, 0, n, perm);
        return ans;
    }
};