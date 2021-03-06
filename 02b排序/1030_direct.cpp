class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) 
    {
        vector<vector<int>> ans;
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                ans.push_back({i, j});
            }
        }
        // ²¶»ñµÄÊÇr0,c0
        sort(ans.begin(), ans.end(), [=](vector<int>& x, vector<int>&y)->bool{
            return abs(x[0] - r0) + abs(x[1] - c0) < abs(y[0] - r0) + abs(y[1] - c0);
        });
        return ans;
    }
};