class Solution {
public:
    vector<vector<int>> perms;

    void backTracing(vector<int>& nums, int depth, const int &n) {
        if (depth == n) {
            perms.push_back(nums);
            return;
        }

        for (int i = depth; i < n; ++i) {
            swap(nums[depth], nums[i]);
            backTracing(nums, depth + 1, n);
            swap(nums[depth], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        const int n = nums.size();
        backTracing(nums, 0, n);
        return perms;
    }
};