class Solution {
public:
    constexpr static int dx[4] = {0, -1, 0, 1};
    constexpr static int dy[4] = {1, 0, -1, 0};

    int my_dfs(vector<vector<int>>& grid, int x, int y, int m, int n)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || !grid[x][y])
            return 1;
        if (grid[x][y] == 2)
            return 0;
        
        grid[x][y] = 2;
        int ret = 0;
        for (int k = 0; k < 4; ++k)
        {
            int tx = x + dx[k];
            int ty = y + dy[k];
            ret += my_dfs(grid, tx, ty, m, n);
        }
        return ret;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {   
                if (grid[i][j])
                    ans += my_dfs(grid, i, j, m, n);
            }
        }
        return ans;
    }
};