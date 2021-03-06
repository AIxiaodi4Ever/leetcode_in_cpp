class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            int profit = prices[i] - prices[i - 1];
            if (profit > 0)
                ret += profit; 
        }
        return ret;
    }
};