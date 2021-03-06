class Solution {
public:
    static constexpr int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = heights.size();
        int n = heights[0].size();
        int left = 0, right = 999999, ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            queue<pair<int, int>> q;
            q.emplace(0, 0);
            vector<int> seen(m * n, 0);
            seen[0] = 1;
            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] && abs(heights[nx][ny] - heights[x][y]) <= mid)
                    {
                        q.emplace(nx, ny);
                        seen[nx * n + ny] = 1;
                    }
                }
            }
            if (seen[m * n - 1])
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};