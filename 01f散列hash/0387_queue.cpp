class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> wordsIndex;
        queue<pair<int, int>> q;
        int sz = s.size();
        for (int i = 0; i < sz; ++i)
        {
            if (!wordsIndex.count(s[i]))
            {
                wordsIndex[s[i]] = i;
                q.emplace(s[i], i);
            }
            // ÑÓ³ÙÉ¾³ý
            else
            {
                wordsIndex[s[i]] = -1;
                while (!q.empty() && wordsIndex[q.front().first] == -1)
                    q.pop();
            }
        }
        return q.empty() ? -1 : q.front().second; 
    }
};