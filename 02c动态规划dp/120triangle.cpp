// leetcode:120
/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路：动态规划+空间优化
// 1.t[i][j]表示从triangle[0][0]到triangle[i][j]的最小路径和；
// 2.因为只能走相邻的点，所以有状态转移方程：
// t[i][j] = min(t[i-1][j-1], t[i-1][j]) + triangle[i][j];
// 在j = 0及j = i时上式不成立，两个边界的转移方程为：
// j = 0: t[i][j] = t[i - 1][j] + triangle[i][j],  j = i: t[i][j] = t[i-1][j-1] + triangle[i][j];
// 3.由上面的转移方程可知，t[i][j]只与上一行i-1行的数据有关，因此可以根据奇，偶性建立两个向量，从而节省时间。

// 如果没有最外面的括号，min()之后如果有表达式会与分号后面的b结合
#define min(a,b) ((a) < (b) ? a : b)

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    int dp[2][triangleSize];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i++)
    {
        int curr = i % 2;
        int prev = 1 - curr;
        // 计算第一列
        dp[curr][0] = dp[prev][0] + triangle[i][0];
        for (int j = 1; j < i; j++)
        {
            // 计算中间项
            dp[curr][j] = min(dp[prev][j - 1], dp[prev][j]) + triangle[i][j];
        }
        // 计算最后一列（对角线）
        dp[curr][i] = dp[prev][i - 1] + triangle[i][i];
    }
    int last_row_index = (triangleSize - 1) % 2;
    int ret = dp[last_row_index][0];
    for (int i = 0; i < triangleSize; i++)
    {
        ret = min(ret, dp[last_row_index][i]);
    }
    return ret;
}

// 如果倒序遍历j，即从i到0遍历，则只需要一个n维向量即可；
// 因为倒序遍历时，计算dp[j]时对应的元素dp[j]及dp[j-1]并没有改变，仍然是上次计算的值。
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    int dp[triangleSize];
    memset(dp, 0, sizeof(dp));
    dp[0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i++)
    {
        // 对角线
        dp[i] = dp[i - 1] + triangle[i - 1][i - 1];
        for (int j = i - 1; j != 0; j--)
        {
            // 中间项
            dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
        }
        // 第一列（放在循环之前也可以）
        dp[0] = dp[0] + triangle[i][0];
    }
    int ret = dp[0];
    for (int i = 0; i < triangleSize; i++)
    {
        ret = min(ret, dp[i]);
    }
    return ret;
}

// 也存在从最后一列开始的dp
// 同时也可以在原数组里修改元素，实际做时需要询问1.空间复杂度要求。2.是否可以修改原数组。