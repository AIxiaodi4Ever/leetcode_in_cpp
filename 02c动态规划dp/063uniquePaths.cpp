// leetcode:063
/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路：动态规划
// 因为机器人只能向下或者向右走；
// f[i,j]表示从0,0出发到达目标位置i,j的路径数，显然f[i,j] = f[i-1,j] + f[i,j-1]，任意i',j'大于i,j无关;
// 当某一个位置有障碍时，该位置的f=0;
// 可以写出一个用二维数组表示的O(mn)时间复杂度和空间复杂度的程序；
// 使用滚动数组，一行一行的求解，则节省空间为线性；

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    int n = obstacleGridSize, m = *obstacleGridColSize;
    // 初始化为0
    int f[m] = { };
    f[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < obstacleGridSize; i++)
    {
        // 一行的每一列
        for (int j = 0; j < *obstacleGridColSize; j++)
        {
            if (obstacleGrid[i][j] == 1)
                f[j] = 0;

            else if (j - 1 >= 0)
                f[j] += f[j - 1]; // 原来的f[j]表示f[i-1,j],,f[j-1]则表示f[i,j-1],求和以后f[j]=f[i,j];
        }
    }

    return f[m - 1];
}

