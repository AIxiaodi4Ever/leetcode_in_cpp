/* 
题目描述：
    Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally 
or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

/* 
解题思路：
    遍历矩阵，遇到'1'则进行DFS使所有临近节点为'0'，然后ans++，最后返回ans
*/

void depth_first_walk(char **grid, int x, int y, int colmax, int rowmax)
{
    if (grid[y][x] == '0')
        return;

    grid[y][x] = '0';
    int directions[5] = {-1, 0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        // index start at 0, so when judge colmax or rowmax use '>='
        if (x + directions[i] < 0 || x + directions[i] >= colmax
            || y + directions[i + 1] < 0 || y + directions[i + 1] >= rowmax)
            continue;

        depth_first_walk(grid, x + directions[i], y + directions[i + 1], colmax, rowmax);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int rowmax;
    int colmax;
    int x, y;
    int ans = 0;

    if (grid == NULL || gridSize == 0)
        return 0;

    rowmax = gridSize;
    colmax = gridColSize[0];
    for (x = 0; x < colmax; x++)
    {
        for (y = 0; y < rowmax; y++)
        {
            if (grid[y][x] == '1')
            {
                depth_first_walk(grid, x, y, colmax, rowmax);
                ans++;
            }
        }
    }
    return ans;
}