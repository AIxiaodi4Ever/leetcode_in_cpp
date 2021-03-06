class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) 
    {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c)
            return nums;

        vector<vector<int>> ret(r, vector<int>(c));
        for (int i = 0; i < m * n; ++i)
        {
            ret[i / c][i % c] = nums[i / n][i % n];
        }        

        return ret;
    }
};