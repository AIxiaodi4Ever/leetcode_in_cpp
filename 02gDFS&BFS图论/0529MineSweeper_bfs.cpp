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

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        queue<pair<int, int>> safeSquares;
        safeSquares.push({click[0], click[1]});
        int m = board.size(), n = board[0].size();
        // this is critical!!
        // bfs需要手动标记已访问节点，否则会超时
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // 设置第一个点为已访问
        vis[click[0]][click[1]] = 1;

        while (!safeSquares.empty())
        {
            int x = safeSquares.front().first, y = safeSquares.front().second;
            safeSquares.pop();

            int minesSurround = 0;
            // 因为不能删除队列尾巴处的元素，所以需要两边遍历。。
            // 第一遍检查是否有mine
            for (int i = 0; i < 8; ++i)
            {
                int mx = x + dx[i], my = y + dy[i];
                // 越界
                if (mx < 0 || mx >= m || my < 0 || my >= n)
                    continue;
                minesSurround += board[mx][my] == 'M';             
            }


            if (minesSurround)
            {
                board[x][y] = minesSurround + '0';
            }
            
            // 如果周围没有雷，第二遍寻找E
            else
            {
                board[x][y] = 'B';
                
                for (int i = 0; i < 8; ++i)
                {
                    int mx = x + dx[i], my = y + dy[i];
                    // 越界
                    if (mx < 0 || mx >= m || my < 0 || my >= n || board[mx][my] != 'E' 
                        || vis[mx][my])
                        continue;
                        safeSquares.push({mx, my});
                        vis[mx][my] = 1;
                }
            }
        }
        return board;
    }
};