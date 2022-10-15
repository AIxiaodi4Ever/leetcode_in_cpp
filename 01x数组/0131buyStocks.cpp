class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e4;
        int maxProfit = 0;
        for (int &price : prices) {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(price, minPrice);
        }
        return maxProfit;
    }
};