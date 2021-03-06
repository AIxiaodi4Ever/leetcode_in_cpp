class Solution {
public:
    int dfs(string s, int left, int right, int k)
    {
        vector<int> cnt(26, 0);
        for (int i = left; i <= right; ++i)
        {
            ++cnt[s[i] - 'a'];
        }
        char split = 0;
        for (int i = 0; i < 26; ++i)
        {
            // 必须排除cnt[i]==0的情况
            if (cnt[i] > 0 && cnt[i] < k)
            {
                split = i + 'a';
                break;
            }
        }
        if (split == 0)
            return right - left + 1;

        int i = left;
        int ret = 0;
        while (i <= right)
        {
            while (i <= right && s[i] == split)
                ++i;
            if (i > right)
                break;
            int start = i;
            while (i <= right && s[i] != split)
                ++i;
            ret = max(ret, dfs(s, start, i - 1, k));
        }
        return ret;
    }

    int longestSubstring(string s, int k) 
    {
        int n = s.size();
        return dfs(s, 0, n - 1, k);
    }
};