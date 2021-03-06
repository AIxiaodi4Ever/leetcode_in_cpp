class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cookiesNum = s.size(), childrenNum = g.size();
        int ans = 0;
        for (int i = 0, j = 0; i < childrenNum && j < cookiesNum; ++i, ++j)
        {
            while (j < cookiesNum && g[i] > s[j])
                ++j;
            if (j < cookiesNum) 
                ++ans;
        }
        return ans;
    }
};