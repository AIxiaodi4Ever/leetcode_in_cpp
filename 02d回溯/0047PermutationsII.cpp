class Solution {
public:
    vector<bool> vis;

    void my_backtracing(vector<int>& nums, vector<vector<int>>& ans, vector<int>& perm, int pos)
    {
        if (pos == nums.size())
        {
            ans.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]))
                continue;
            perm.push_back(nums[i]);
            vis[i] = true;
            my_backtracing(nums, ans, perm, pos + 1);
            perm.pop_back();
            vis[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        my_backtracing(nums, ans, perm, 0);
        return ans;
    }
};