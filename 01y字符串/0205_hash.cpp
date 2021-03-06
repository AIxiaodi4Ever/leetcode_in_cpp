class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < len; ++i)
        {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x))
                return false;
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }   
};