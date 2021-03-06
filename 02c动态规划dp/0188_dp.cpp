class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        k = min(k, n / 2);
        // 单独买入不算交易次数，第i次交易以卖出为算
        vector<vector<int>> hold(n, vector<int>(k + 1));
        vector<vector<int>> unhold(n, vector<int>(k + 1));

        // 边界条件，0次交易时不持有股票的最大收益都为0
        // 0次交易时持有股票的最大收益为hold[0][0] = -prices[0], hold[i][0] = max(hold[i-1][0], -prices[i]); 
        hold[0][0] = -prices[0];
        unhold[0][0] = 0;
        for (int i = 1; i <= k; ++i)
            hold[0][i] = unhold[0][i]=  INT_MIN / 2;
        
        for (int i = 1; i < n; ++i)
        {
            // unhold[i][0]始终为0，所以在这里为hold赋值，之后j从1开始循环
            hold[i][0] = max(hold[i - 1][0], -prices[i]);
            for (int j = 1; j <= k; ++j)
            {
                hold[i][j] = max(hold[i - 1][j], unhold[i - 1][j] - prices[i]);
                unhold[i][j] = max(unhold[i - 1][j], hold[i - 1][j - 1] + prices[i]);
            }
        }

        return *max_element(unhold[n - 1].begin(), unhold[n - 1].end());
    }
};