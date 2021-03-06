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
            // ÿ�α������ô���ӵ�ǰ���㵽�¸������ ����ҿ� ��������ж���
            for (int i = 0; i < 4; ++i)
            {
                // y�����£�x�����ң�y����Ϊr��x����Ϊc
                // ���������º������ϵ���������Ϊrow == r0
                // �����Ϻ����µ���������Ϊcol == c0
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