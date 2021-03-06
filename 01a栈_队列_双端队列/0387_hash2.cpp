class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> wordsIndex;
        int sz = s.size();
        for (int i = 0; i < sz; ++i)
        {
            if (wordsIndex.count(s[i]))
                wordsIndex[s[i]] = -1;
            else
                wordsIndex[s[i]] = i;
        }
        int first = sz;
        for (auto [_, pos] : wordsIndex)
        {
            if (pos != -1 && pos < first)
                first = pos;
        }
        if (first == sz)
            return -1;
        return first;
    }
};