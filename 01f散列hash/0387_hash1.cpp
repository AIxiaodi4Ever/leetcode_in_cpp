class Solution {
public:
    int firstUniqChar(string s) 
    {
        vector<int> wordsFreq(26, 0);
        for (const char &c : s)
        {
            ++wordsFreq[c - 'a'];
        }
        int sz = s.size();
        for (int i = 0; i < sz; ++i)
        {
            if (wordsFreq[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};