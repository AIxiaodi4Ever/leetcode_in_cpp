class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void my_backtracing(int pos, vector<int>& nums)
    {
        for (int i = pos; i < nums.size(); ++i)
        {
            temp.push_back(nums[i]);
            ans.push_back(temp);
            my_backtracing(i + 1, nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        ans.push_back(temp);
        my_backtracing(0, nums);
        return ans;
    }
};