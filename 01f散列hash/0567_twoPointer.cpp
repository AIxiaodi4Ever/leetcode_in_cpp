class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.size(), m = s2.size();
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; ++i)
            --cnt[s1[i] - 'a'];

        int left = 0, right = 0
        while (right < m)   // m´íÐ´³Én
        {
            int x = s2[right] - 'a';
            ++cnt[x];
            while (cnt[x] > 0)
            {
                --cnt[s2[left] - 'a'];
                ++left;
            }
            if (right - left + 1 == n)
                return true;
            ++right;
        }
        return false;
    }
};