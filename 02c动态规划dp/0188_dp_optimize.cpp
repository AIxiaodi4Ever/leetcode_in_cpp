class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        k = min(k, n / 2);
        vector<int> hold(k + 1);
        vector<int> unhold(k + 1);

        hold[0] = -prices[0];
        unhold[0] = 0;
        for (int i = 1; i <= k; ++i)
            hold[i] = unhold[i] = INT_MIN / 2;
        for (int i = 0; i < n; ++i)
        {
            hold[0] = max(hold[0], unhold[0] - prices[i]);
            for (int j = 1; j <= k; ++j)
            {
                // 卖了之后交易次数才会+1
                // 先计算hold后值可能会改变，但不影响计算结果
                hold[j] = max(hold[j], unhold[j] - prices[i]);
                unhold[j] = max(unhold[j], hold[j - 1] + prices[i]);
            }
        }

        return *max_element(unhold.begin(), unhold.end());
    }
};