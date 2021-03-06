class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.size(), m = s2.size();
        // s1比s2长，一定不可能
        if (n > m)
            return false;
        vector<int> cnt(26, 0);
        // s1是--，s2是++，这样方便后面遍历s2时移入加移出减，否则就要反着来
        for (int i = 0; i < n; ++i)
        {
            --cnt[s1[i] - 'a'];
            ++cnt[s2[i] - 'a'];
        }
        int diff = 0;
        for (int c : cnt)
        {
            if (c != 0)
                ++diff;
        }
        if (diff == 0)  
            return true;

        // 下面的代码没考虑初始的窗口，所以前面要加if
        for (int i = n; i < m; ++i)
        {
            int x = s2[i - n] - 'a', y = s2[i] - 'a';
            if (x == y)
                continue;
            // 移除x
            if (cnt[x] == 0)
                ++diff;
            --cnt[x];
            if (cnt[x] == 0)
                --diff;

            // 加入y
            if (cnt[y] == 0)
                ++diff;
            ++cnt[y];
            if (cnt[y] == 0)
                --diff;
            if (diff == 0)
                return true;
        }
        return false;
    }
};