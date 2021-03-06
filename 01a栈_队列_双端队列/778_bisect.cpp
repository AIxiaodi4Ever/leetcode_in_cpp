class Solution {
public:
    static constexpr int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool check(vector<vector<int>>& grid, int threshold)
    {
        if (grid[0][0] > threshold)
            return false;
        int n = grid.size();
        vector<bool> visited(n * n, false);
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        visited[0] = true;
        while (!q.empty())
        {
            auto [x, y]= q.front();
            q.pop();
            int idx = x * n + y;
            if (x == n - 1 && y == n - 1)
                break;
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    int idx2 = nx * n + ny;
                    if (!visited[idx2] && grid[nx][ny] <= threshold)
                    {
                        q.push(make_pair(nx, ny));
                        visited[nx * n + ny] = true;
                    }
                }
            }
        }
        return visited[n * n - 1];
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0, right = n * n - 1;
        int mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (check(grid, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};