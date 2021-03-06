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

Surrounded regions shouldn��t be on the border, which means that any 'O' on the border of the 
board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 
'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells 
connected horizontally or vertically.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/surrounded-regions
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    void solve(vector<vector<char>>& board) 
    {
        int row = board.size();
        if (!row)
            return;
        int col = board[0].size();
        // ��Ϊ���ñ����ʼ���������Ի�����pair��
        queue<pair<int, int>> marks;
        // ��������
        for (int j = 0; j < col; ++j)
        {
            if (board[0][j] == 'O')
                marks.push({0, j});
            if (board[row - 1][j] == 'O')
                marks.push({row - 1, j});
        }
        // ��������
        for (int i = 1; i < row - 1; ++i)
        {
            if (board[i][0] == 'O')
                marks.push({i, 0});
            if (board[i][col - 1] == 'O')
                marks.push({i, col - 1});
        }

        while (!marks.empty())
        {
            int x = marks.front().first, y = marks.front().second;
            marks.pop();
            board[x][y] = 'A';
            // һ��ʼ��,x,y������i,j���º������i��ͻ������
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= row || ny < 0 || ny >= col || board[nx][ny] != 'O')
                    continue;
                marks.push({nx, ny});
            }
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