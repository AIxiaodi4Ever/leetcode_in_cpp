class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int n = s.size();
        vector<int> diffs(n, 0);
        for (int i = 0; i < n; ++i)
            diffs[i] = abs(t[i] - s[i]);
        int head = 0, tail = 0;
        int sum = 0;
        int maxLen = 0;
        while (tail < n)
        {
            sum += diffs[tail];
            while (sum > maxCost)
            {
                sum -= diffs[head++];
            }
            maxLen = max(maxLen, tail - head + 1);
            ++tail;
        }
        return maxLen;
    }
};