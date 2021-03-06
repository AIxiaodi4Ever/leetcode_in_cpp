class Solution {
public:
    static constexpr int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int> dist(n * n, INT_MAX);
        vector<bool> visited(n * n, false);
        dist[0] = grid[0][0];

        auto tupleCmp = [](const auto&e1, const auto &e2)->bool {
            return get<2>(e1) > get<2>(e2);
        };

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(tupleCmp)> q(tupleCmp);
        q.emplace(0, 0, grid[0][0]);
        while (!q.empty())
        {
            const auto [x, y, t] = q.top();
            q.pop();
            int idx = x * n + y;
            if (visited[idx])
                continue;
            visited[idx] = true;
            if (x == n - 1 && y == n - 1)
                break;
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    int idx2 = nx * n + ny;
                    if (!visited[idx2])
                    {
                        if (grid[nx][ny] <= grid[x][y])
                        {
                            dist[idx2] = dist[idx];
                            q.emplace(nx, ny, dist[idx2]);
                        }
                        else 
                        {
                            dist[idx2] = max(dist[idx], grid[nx][ny]);
                            q.emplace(nx, ny, dist[idx2]);
                        }
                    }
                }
            }
        }
        return dist[n * n - 1];
    }
};