class Solution {
public:
    static constexpr int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    bool flag = false;
                    queue<pair<int, int>> que;
                    que.push({i, j});
                    vis[i][j] = true;
                    while (!que.empty()) {
                        auto p = que.front();
                        que.pop();
                        if (grid1[p.first][p.second] != 1) {
                            flag = true;
                        }
                        for (int k = 0; k < 4; ++k) {
                            int x = p.first + dir[k][0];
                            int y = p.second + dir[k][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1 && !vis[x][y]) {
                                que.push({x, y});
                                vis[x][y] = true;
                            }
                        }//k
                    }//que     
                    if (!flag) {
                        ++ans;
                    }
                }
            }//j
        }//i
        return ans;
    }
};