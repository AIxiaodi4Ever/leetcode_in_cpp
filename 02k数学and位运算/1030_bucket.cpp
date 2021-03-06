class Solution {
public:
    int dist(int r, int r0, int c, int c0)
    {
        return abs(r - r0) + abs(c - c0);
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) 
    {
        int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector<vector<vector<int>>> buckets(maxDist + 1);
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                int d = dist(i, r0, j, c0);
                buckets[d].push_back({i, j});
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i <= maxDist; ++i)
        {
            for (const auto& it : buckets[i])
                ans.push_back(it);
        }
        return ans;
    }
};  