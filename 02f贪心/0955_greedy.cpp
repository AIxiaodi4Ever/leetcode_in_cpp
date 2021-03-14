class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<string> orderedStrs(n);
        vector<string> cur(n);
        int ans = 0;
        for (int j = 0; j < m; ++j)
        {
            cur = orderedStrs;
            for (int i = 0; i < n; ++i)
                cur[i] += strs[i][j];
            if (isSorted(cur))
                orderedStrs = cur;
            else 
                ++ans;
        }
        return ans;
    }

    bool isSorted(vector<string>& cur)
    {
        int n = cur.size();
        for (int i = 0; i < n - 1; ++i)
        {
            if (cur[i] > cur[i + 1])
                return false;
        }
        return true;
    }
};