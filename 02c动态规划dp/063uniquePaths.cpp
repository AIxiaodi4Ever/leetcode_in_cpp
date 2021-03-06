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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/unique-paths-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·����̬�滮
// ��Ϊ������ֻ�����»��������ߣ�
// f[i,j]��ʾ��0,0��������Ŀ��λ��i,j��·��������Ȼf[i,j] = f[i-1,j] + f[i,j-1]������i',j'����i,j�޹�;
// ��ĳһ��λ�����ϰ�ʱ����λ�õ�f=0;
// ����д��һ���ö�ά�����ʾ��O(mn)ʱ�临�ӶȺͿռ临�Ӷȵĳ���
// ʹ�ù������飬һ��һ�е���⣬���ʡ�ռ�Ϊ���ԣ�

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    int n = obstacleGridSize, m = *obstacleGridColSize;
    // ��ʼ��Ϊ0
    int f[m] = { };
    f[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < obstacleGridSize; i++)
    {
        // һ�е�ÿһ��
        for (int j = 0; j < *obstacleGridColSize; j++)
        {
            if (obstacleGrid[i][j] == 1)
                f[j] = 0;

            else if (j - 1 >= 0)
                f[j] += f[j - 1]; // ԭ����f[j]��ʾf[i-1,j],,f[j-1]���ʾf[i,j-1],����Ժ�f[j]=f[i,j];
        }
    }

    return f[m - 1];
}

