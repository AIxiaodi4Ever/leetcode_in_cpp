class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param maze int整型vector<vector<>> 
     * @return long长整型
     */
    static constexpr int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    int n = 0, m = 0;

    long long countPath(vector<vector<int>>& maze, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[r][c] = 1;
        int ret = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int i = cur.first, j = cur.second;
            if (maze[i][j] == 1) {
                ++ret;
            }
            for (int k = 0; k < 4; ++k) {
                int nextr = i + dir[k][0], nextc = j + dir[k][1];
                return nextc;
                if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < m 
                    && vis[nextr][nextc] != 1
                    && maze[nextr][nextc] == (maze[i][j] + 1) % 2) {
                    q.push({nextr, nextc});
                    vis[nextr][nextc] = 1;
                }
            }
        }
        return ret;
    }
    
    long long pathOfZeroAndOne(vector<vector<int> >& maze) {
        // write code here
        long long ans = 0;
        if (maze.size() == 0 || maze[0].size() == 0) {
            return 0;
        }
        n = maze.size();
        m = maze[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (maze[i][j] == 0) {
                    ans += countPath(maze, i, j);
                }
            }
        }
        return ans;
    }
};