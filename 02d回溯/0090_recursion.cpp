class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;

    void dfs(bool choosePre, int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }

        dfs(false, cur + 1, nums);
        if (!choosePre && cur > 0 && nums[cur] == nums[cur - 1]) {
            return;
        }
        
        t.push_back(nums[cur]);
        dfs(true, cur + 1, nums);
        t.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(false, 0, nums);
        return ans;
    }
};