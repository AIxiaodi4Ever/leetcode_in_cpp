class Solution {
public:
    constexpr static int dx[4] = {0, -1, 0, 1};
    constexpr static int dy[4] = {1, 0, -1, 0};

    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j])
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        if (tx < 0 || tx >= n || ty < 0 || ty >= n || !grid[tx][ty])
                            ++perimeter;
                    }
                }
            }
        }
        return perimeter;
    }
};