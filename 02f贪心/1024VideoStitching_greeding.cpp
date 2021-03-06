class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) 
    {
        int last = 0, pre = 0, ret = 0;
        vector<int> maxn(T);
        for (const vector<int>& clip : clips)
        {
            if (clip[0] < T)
                maxn[clip[0]] = max(clip[1], maxn[clip[0]]);
        }
        for (int i = 0; i < T; ++i)
        {
            last = max(last, maxn[i]);
            if (i == last)
                return -1;
            if (i == pre)
            {
                pre = last;
                ++ret;
            }
        }
        return ret;
    }
};