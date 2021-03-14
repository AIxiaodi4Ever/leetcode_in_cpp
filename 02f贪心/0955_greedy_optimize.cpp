class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> cut(n - 1);
        int ans = 0;
        bool ordered = true;
        for (int j = 0; j < m; ++j)
        {
            for (int i = 0; i < n - 1; ++i)
            {
                if (!cut[i] && strs[i][j] > strs[i + 1][j])
                {
                    ++ans;
                    ordered = false;
                    break;
                }
            }
            if (ordered)
            {
                for (int i = 0; i < n - 1; ++i)
                {
                    if (strs[i][j] < strs[i + 1][j])
                        cut[i] = true;
                }
            }
            ordered = true;
        }
        return ans;
    }
};