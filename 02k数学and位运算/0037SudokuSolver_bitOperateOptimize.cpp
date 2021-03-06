class Solution {
private:
    int line[9];
    int column[9];
    int block[3][3];
    int valid;
    vector<pair<int, int>> spaces;
public:
    void flip(int i, int j, int num)
    {
        line[i] ^= (1 << num);
        column[j] ^= (1 << num);
        block[i / 3][j / 3] ^= (1 << num);
    }

    void my_solver(int position, vector<vector<char>>& board)
    {
        if (position == spaces.size())
        {
            valid = true;
            return;
        }

        auto [i, j] = spaces[position];
        int mask = ~(line[i] | column[j] | block[i/3][j/3]) & 0x1ff;
        // 不要忘记!valid这个条件，否则超时且答案错误
        // 还有mask &= 不是 mask&
        for (; mask && !valid; mask &= (mask - 1))
        {
            int digitMask = mask & (-mask);
            int digit = __builtin_ctz(digitMask);
            board[i][j] = digit + '0' + 1;
            flip(i, j, digit);
            my_solver(position + 1, board);
            flip(i, j, digit);
            
        }
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        memset(line, 0, sizeof(line));
        memset(column, 0, sizeof(column));
        memset(block, 0, sizeof(block));
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
                    flip(i, j, num);
                }
            }
        }
        my_solver(0, board);
    }
};