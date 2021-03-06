class Solution {
private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    vector<pair<int, int>> spaces;
public:
    void my_solver(int position, vector<vector<char>>& board)
    {
        if (position == spaces.size())
        {
            valid = true;
            return;
        }
        // 老老实实用auto...
        // 也可以用pair<int, int> posp, posp.first, posp.second
        auto [i, j] = spaces[position];
        // 不要忘记!valid这个条件，否则超时且答案错误
        for (int digit = 0; digit < 9 && !valid; ++digit)
        {
            if (!line[i][digit] && !column[j][digit] && !block[i/3][j/3][digit])
            {
                board[i][j] = digit + '0' + 1;
                // 对应位置上将索引置位true
                line[i][digit] = column[j][digit] = block[i/3][j/3][digit] = true;
                my_solver(position + 1, board);
                line[i][digit] = column[j][digit] = block[i/3][j/3][digit] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    spaces.emplace_back(i, j);
                else
                {
                    int num = board[i][j] - '0' - 1;
                    line[i][num] = true;
                    // 这里把j写成i出错
                    column[j][num] = true;
                    block[i/3][j/3][num] = true;
                }
            }
        }
        my_solver(0, board);
    }
};