class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> tmp;
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (i > 0 && (mask & (1 << (i - 1))) == 0 && nums[i] == nums[i - 1]) {
                        flag = false;
                        break;
                    }
                    tmp.push_back(nums[i]);
                }
            }
            if (flag) {
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};