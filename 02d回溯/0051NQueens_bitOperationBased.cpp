class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> solutions;
        vector<int> queens(n, -1);
        solve(solutions, queens, n, 0, 0, 0, 0);
        return solutions;
    }

    void solve(vector<vector<string>>& solutions, vector<int>& queens, int n, int row, int columns, int diagonals1, int diagonals2)
    {
        if (row == n)
        {
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
        }
        else
        {
            // 左右移的优先级低于算数运算，，
            int availablePosition = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePosition != 0)
            {
                // 获得最靠前的可用列数
                // 同时用于更新三个N位二进制数
                int position = availablePosition & (-availablePosition);
                // 光按位与忘记赋值
                availablePosition = availablePosition & (availablePosition - 1);
                // __builtin_ctz(x)获得数字x二进制表示时末尾0的个数
                int column = __builtin_ctz(position);
                queens[row] = column;
                solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1);
                // 不需要剪枝因为3个N位数没变，只是传递了拷贝
                queens[row] = -1;
            }
        }
    }

    vector<string> generateBoard(const vector<int>& queens, int n)
    {
        vector<string> board;
        for (int i = 0; i < n; ++i)
        {
            string row(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};