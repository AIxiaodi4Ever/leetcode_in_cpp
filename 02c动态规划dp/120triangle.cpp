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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/triangle
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·����̬�滮+�ռ��Ż�
// 1.t[i][j]��ʾ��triangle[0][0]��triangle[i][j]����С·���ͣ�
// 2.��Ϊֻ�������ڵĵ㣬������״̬ת�Ʒ��̣�
// t[i][j] = min(t[i-1][j-1], t[i-1][j]) + triangle[i][j];
// ��j = 0��j = iʱ��ʽ�������������߽��ת�Ʒ���Ϊ��
// j = 0: t[i][j] = t[i - 1][j] + triangle[i][j],  j = i: t[i][j] = t[i-1][j-1] + triangle[i][j];
// 3.�������ת�Ʒ��̿�֪��t[i][j]ֻ����һ��i-1�е������йأ���˿��Ը����棬ż�Խ��������������Ӷ���ʡʱ�䡣

// ���û������������ţ�min()֮������б��ʽ����ֺź����b���
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
        // �����һ��
        dp[curr][0] = dp[prev][0] + triangle[i][0];
        for (int j = 1; j < i; j++)
        {
            // �����м���
            dp[curr][j] = min(dp[prev][j - 1], dp[prev][j]) + triangle[i][j];
        }
        // �������һ�У��Խ��ߣ�
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

// ����������j������i��0��������ֻ��Ҫһ��nά�������ɣ�
// ��Ϊ�������ʱ������dp[j]ʱ��Ӧ��Ԫ��dp[j]��dp[j-1]��û�иı䣬��Ȼ���ϴμ����ֵ��
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    int dp[triangleSize];
    memset(dp, 0, sizeof(dp));
    dp[0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i++)
    {
        // �Խ���
        dp[i] = dp[i - 1] + triangle[i - 1][i - 1];
        for (int j = i - 1; j != 0; j--)
        {
            // �м���
            dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
        }
        // ��һ�У�����ѭ��֮ǰҲ���ԣ�
        dp[0] = dp[0] + triangle[i][0];
    }
    int ret = dp[0];
    for (int i = 0; i < triangleSize; i++)
    {
        ret = min(ret, dp[i]);
    }
    return ret;
}

// Ҳ���ڴ����һ�п�ʼ��dp
// ͬʱҲ������ԭ�������޸�Ԫ�أ�ʵ����ʱ��Ҫѯ��1.�ռ临�Ӷ�Ҫ��2.�Ƿ�����޸�ԭ���顣