// 解题思路：动态规划
// 1.dp[i][j]表示从位置i,j到右下角的最小path，因为只能向下或向右移动，所以dp[i][j]满足：
// dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j]。
// 实际计算中i+1和j+1可能越界，因此可以对最后一行和最后一列单独计算。
// 并且可以使用滚动数组的方法将空间复杂度简化为O(n),n为列数。

// 也可以令dp[i][j]表示从左上角到[i][j]的最短path，从第一行开始dp；

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {   
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,0);
        // 初始化右下角位置
        dp[n - 1] = grid[m - 1][n - 1];

        // 先计算最后一行
        for (int j = n - 2; j >= 0; --j)
        {
            dp[j] = dp[j + 1] + grid[m - 1][j];
        }

        for (int i = m - 2; i >= 0; --i)
        {
            // 每行最后一列直接计算
            dp[n - 1] = dp[n - 1] + grid[i][n - 1];
            for (int j = n - 2; j >= 0; --j)
            {
                dp[j] = min(dp[j], dp[j + 1]) + grid[i][j];
            }
        }
        return dp[0];
    }
};