class Solution {
public:
    static constexpr int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};

        int rows = matrix.size(), columns = matrix[0].size();
        int total = rows * columns;
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        vector<int> ans(total);

        int r = 0, c = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; ++i)
        {
            ans[i] = matrix[r][c];
            visited[r][c] = true;
            int next_r = r + directions[directionIndex][0];
            int next_c = c + directions[directionIndex][1];
            if (next_r < 0 || next_r >= rows || next_c < 0 || next_c >= columns || visited[next_r][next_c]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            r += directions[directionIndex][0];
            c += directions[directionIndex][1];
        }
        return ans;
    }
};