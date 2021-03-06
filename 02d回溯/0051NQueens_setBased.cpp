class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> solutions;
        // 存储每一种可能的列组合
        vector<int> queens(n, -1);
        unordered_set<int> columns;
        unordered_set<int> diagonals1;
        unordered_set<int> diagonals2;
        backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }

    void backtrack(vector<vector<string>> &solutions, vector<int> queens, int n, int row, unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2)
    {
        // ==又写成了=
        if (row == n)
        {
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                // 不等于表示找到了
                if (columns.find(i) != columns.end())
                    continue;
                int diag1 = row - i;
                if (diagonals1.find(diag1) != diagonals1.end())
                    continue;
                int diag2 = row + i;
                if (diagonals2.find(diag2) != diagonals2.end())
                continue;

                queens[row] = i;
                columns.insert(i);
                diagonals1.insert(diag1);
                diagonals2.insert(diag2);
                // 递归
                backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
                // （时空）回溯
                // 剪枝
                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diag1);
                diagonals2.erase(diag2);

            }
        }
    }

    vector<string> generateBoard(const vector<int> &queens, int n)
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