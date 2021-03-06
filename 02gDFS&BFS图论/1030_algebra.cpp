class Solution {
public:
    int dr[4] = {1, 1, -1, -1};
    int dc[4] = {1, -1, -1, 1};
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) 
    {
        int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector<vector<int>> ans;
        ans.push_back({r0, c0});
        int row = r0;
        int col = c0;
        for (int dist = 1; dist <= maxDist; ++dist)
        {
            --row;
            // 每次遍历正好处理从当前顶点到下个顶点的 左闭右开 区间的所有顶点
            for (int i = 0; i < 4; ++i)
            {
                // y轴向下，x轴向右，y坐标为r，x坐标为c
                // 所以向右下和向左上的收敛条件为row == r0
                // 向右上和左下的收敛条件为col == c0
                while ((i % 2 == 0 && row != r0) || (i % 2 != 0 && col != c0))
                {
                    if (row >= 0 && row < R && col >= 0 && col < C)
                        ans.push_back({row, col});
                    row += dr[i];
                    col += dc[i];
                }
            }//i
        }//dist
    return ans;
    }
};