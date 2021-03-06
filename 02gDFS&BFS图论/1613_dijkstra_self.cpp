class Solution {
public:
    static constexpr int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<int> dist(m * n, INT_MAX);
        vector<bool> visited(m * n, false);

        auto compare_tuple = [](const auto &e1, const auto &e2)->bool {
            return get<2>(e1) > get<2>(e2);
        };

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compare_tuple)> q(compare_tuple);
        q.emplace(0, 0, 0);

        dist[0] = 0;
        while (!q.empty())
        {
            auto [x, y, v] = q.top();
            q.pop();
            int idx = x * n + y;
            if (visited[idx])
                continue;

            visited[idx] = true;
            if (x == m - 1 && y == n - 1)
                break;

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                int idx2 = nx * n + ny;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && max(v, abs(heights[x][y] - heights[nx][ny])) < dist[idx2])
                {
                    dist[idx2] = max(v, abs(heights[x][y] - heights[nx][ny]));
                    q.emplace(nx, ny, dist[idx2]);
                }
            }
        }
        return dist[m * n - 1];
    }
};