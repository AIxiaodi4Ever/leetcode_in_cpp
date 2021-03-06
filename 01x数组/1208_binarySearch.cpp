class Solution {
public:
    int binarySearch(vector<int>& accDiff, int endPoint, int target)
    {
        int left = 0, right = endPoint;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (accDiff[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int equalSubstring(string s, string t, int maxCost) 
    {
        int n = s.size();
        vector<int> accDiff(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            accDiff[i + 1] = accDiff[i] + abs(t[i] - s[i]);
        }

        int maxLen = 0;
        // accDiff[i]表示前i个数相加，所以对应的末尾索引为i-1
        for (int i = 0; i <= n; ++i)
        {
            int start = binarySearch(accDiff, i, accDiff[i] - maxCost);
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};