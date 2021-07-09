// ����˼·����̬�滮
// 1.dp[i][j]��ʾ��λ��i,j�����½ǵ���Сpath����Ϊֻ�����»������ƶ�������dp[i][j]���㣺
// dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j]��
// ʵ�ʼ�����i+1��j+1����Խ�磬��˿��Զ����һ�к����һ�е������㡣
// ���ҿ���ʹ�ù�������ķ������ռ临�Ӷȼ�ΪO(n),nΪ������

// Ҳ������dp[i][j]��ʾ�����Ͻǵ�[i][j]�����path���ӵ�һ�п�ʼdp��

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {   
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,0);
        // ��ʼ�����½�λ��
        dp[n - 1] = grid[m - 1][n - 1];

        // �ȼ������һ��
        for (int j = n - 2; j >= 0; --j)
        {
            dp[j] = dp[j + 1] + grid[m - 1][j];
        }

        for (int i = m - 2; i >= 0; --i)
        {
            // ÿ�����һ��ֱ�Ӽ���
            dp[n - 1] = dp[n - 1] + grid[i][n - 1];
            for (int j = n - 2; j >= 0; --j)
            {
                dp[j] = min(dp[j], dp[j + 1]) + grid[i][j];
            }
        }
        return dp[0];
    }
};