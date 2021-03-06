class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int n = s.size();
        int ret = 0;
        for (int t = 0; t < 26; ++t)
        {
            int left = 0, right = 0;
            vector<int> cnt(26, 0);
            int total = 0, less = 0;
            while (right < n)
            {
                ++cnt[s[right] - 'a'];
                if (cnt[s[right] - 'a'] == 1)
                {
                    ++total;
                    ++less;
                }
                if (cnt[s[right] - 'a'] == k)
                    --less;
                while (total > t)
                {
                    --cnt[s[left] - 'a'];
                    if (cnt[s[left] - 'a'] == 0)
                    {
                        --total;
                        --less;
                    }
                    if (cnt[s[left] - 'a'] == k - 1)
                        ++less;
                    ++left;
                }
                // 先递增right位置区间为左闭右开区间
                ++right;
                if (less == 0)
                    ret = max(ret, right - left);
            }
        }
        return ret;
    }
};