/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X

Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the 
board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 
'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells 
connected horizontally or vertically.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int row, col;

    void myDfs(vector<vector<char>>& board, int r, int c)
    {
        if ( r < 0 || r >= row || c < 0 || c >= col || board[r][c] != 'O')
            return;

        board[r][c] = 'A';
        myDfs(board, r - 1, c);
        myDfs(board, r + 1, c);
        myDfs(board, r, c - 1);
        myDfs(board, r, c + 1);
    }

    void solve(vector<vector<char>>& board) 
    {
        row = board.size();
        // 可能有空的输入
        if (row == 0)
            return;
        // 对第一行取size()，索引从0开始。。
        col = board[0].size();
        // 边界上下两行
        for (int j = 0; j < col; ++j)
        {
            if (board[0][j] == 'O')
                myDfs(board, 0, j);
            if (board[row - 1][j] == 'O')
                myDfs(board, row - 1, j);
        }
        // 边界左右两列
        for (int i = 1; i < row - 1; ++i)
        {
            if (board[i][0] == 'O')
                myDfs(board, i, 0);
            if (board[i][col - 1] == 'O')
                myDfs(board, i, col - 1);
        }
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                    continue;
                }
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                    continue;
                }
            }
        }
    }
};