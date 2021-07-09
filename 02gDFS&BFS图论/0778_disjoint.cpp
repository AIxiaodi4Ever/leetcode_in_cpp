class Solution {
public:
    static constexpr int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int find(vector<int>&f, int x)
    {
        return f[x] < 0 ? x : f[x] = find(f, f[x]);
    }

    bool unite(vector<int>&f, int x, int y)
    {
        x = find(f, x);
        y = find(f, y);
        if (x == y)
            return false;
        if (f[y] < f[x])    
            swap(x, y);
        f[x] += f[y];
        f[y] = x;
        return true;
    }

    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int> uf(n * n, -1);
        vector<pair<int, int>> index(n * n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                index[grid[i][j]] = make_pair(i, j);
        }

        for (int threshold = 0; threshold < n * n; ++threshold)
        {
            auto [x, y] = index[threshold];
            int idx = x * n + y;
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 0 && nx < n && ny >=0 && ny < n && grid[nx][ny] <= threshold)
                    unite(uf, idx, nx * n + ny);
            }
            // 一开始在if后面加了分号。。。
            if (find(uf, 0) == find(uf, n * n - 1))
                return threshold;
        }
        return -1;
    }
};