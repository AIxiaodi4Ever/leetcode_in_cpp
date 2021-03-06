class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        int buy = -prices[0], sell = 0;
        for (int i = 1; i < n; ++i)
        {
            tie(buy, sell) = pair(max(buy, sell - prices[i]), max(sell, buy + prices[i] - fee));
        }
        return sell;
    }
};