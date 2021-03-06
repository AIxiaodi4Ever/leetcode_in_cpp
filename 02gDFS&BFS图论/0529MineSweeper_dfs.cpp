/*
Let's play the minesweeper game (Wikipedia, online game)!
You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 
'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no 
adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents
 how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'),
 return the board after revealing this position according to the following rules:
    If a mine ('M') is revealed, then the game is over - change it to 'X'.
    If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') 
    and all of its adjacent unrevealed squares should be revealed recursively.
    If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') 
    representing the number of adjacent mines.
    Return the board when no more squares will be revealed.

Example 1:
Input: 
[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]
Output: 
[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]


Example 2:
Input: 
[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]
Click : [1,2]
Output: 
[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Note:
    The range of the input matrix's height and width is [1,50].
    The click position will only be an unrevealed square ('M' or 'E'), which also means the input 
    board contains at least one clickable square.
    The input board won't be a stage when game is over (some mines have been revealed).
    For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need 
    to reveal all the unrevealed mines when the game is over, consider any cases that you will win the 
    game or flag any squares.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minesweeper
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int dx[8] = {-1,-1,-1,0,1,1,1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};
    int m, n;

    void myDfs(vector<vector<char>>& board, int x, int y)
    {
        int minesSurround = 0;
        for (int i = 0; i < 8; ++i)
        {
            int mx = x + dx[i], my = y + dy[i];
            if ( mx < 0 || mx >= m || my < 0 || my >= n)
                continue;
            minesSurround += board[mx][my] == 'M';
        }
        if (minesSurround)
        {
            board[x][y] = '0' + minesSurround;
        }
        else
        {
            // 忘记设置该位置为B。。引起递归栈溢出
            // 另外如果访问有序容器越界，则会导致堆溢出
            board[x][y] = 'B';
            for (int i = 0; i < 8; ++i)
            {
                int mx = x + dx[i], my = y + dy[i];
                if ( mx < 0 || mx >= m || my < 0 || my >= n || board[mx][my] != 'E')
                    continue;
                myDfs(board, mx, my);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        m = board.size();
        n = board[0].size();
        myDfs(board, click[0], click[1]);
        return board;
    }
};