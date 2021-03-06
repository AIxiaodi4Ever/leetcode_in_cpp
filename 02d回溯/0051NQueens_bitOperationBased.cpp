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
            // �����Ƶ����ȼ������������㣬��
            int availablePosition = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePosition != 0)
            {
                // ����ǰ�Ŀ�������
                // ͬʱ���ڸ�������Nλ��������
                int position = availablePosition & (-availablePosition);
                // �ⰴλ�����Ǹ�ֵ
                availablePosition = availablePosition & (availablePosition - 1);
                // __builtin_ctz(x)�������x�����Ʊ�ʾʱĩβ0�ĸ���
                int column = __builtin_ctz(position);
                queens[row] = column;
                solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1);
                // ����Ҫ��֦��Ϊ3��Nλ��û�䣬ֻ�Ǵ����˿���
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