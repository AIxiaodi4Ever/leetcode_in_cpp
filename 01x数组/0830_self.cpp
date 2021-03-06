class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) 
    {
        int n = s.size();
        int left = 0, right = 0;
        vector<vector<int>> ret;
        while(left < n)
        {
            while (right + 1 < n && s[right + 1] == s[left])
                ++right;
            if (right - left + 1 >= 3)
                ret.push_back({left, right});
            left = right + 1;
            right = left;
        }
        return ret;
    }
};