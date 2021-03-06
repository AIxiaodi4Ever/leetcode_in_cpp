class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void my_backtracing(int pos, vector<int>& nums)
    {
        if (pos != nums.size())
        {
            temp.push_back(nums[pos]);
            ans.push_back(temp);
            my_backtracing(pos + 1, nums);
            temp.pop_back();
            my_backtracing(pos + 1, nums);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        ans.push_back(temp);
        my_backtracing(0, nums);
        return ans;
    }
};