class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int n = s.size();
        vector<int> diffs(n, 0);
        int head = 0, tail = 0;
        int sum = 0;
        int maxLen = 0;
        while (tail < n)
        {
            sum += abs(t[tail] - s[tail]);
            while (sum > maxCost)
            {
                sum -= abs(t[head] - s[head]);
                ++head;
            }
            maxLen = max(maxLen, tail - head + 1);
            ++tail;
        }
        return maxLen;
    }
};