class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int curSum = 0;
        for (int i = 0; i < k; ++i)
            curSum += cardPoints[i];
        int n = cardPoints.size();
        int maxSum = curSum;
        for (int i = 0; i < k; ++i)
        {
            curSum = curSum - cardPoints[k - i -1] + cardPoints[n - i - 1];
            maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};