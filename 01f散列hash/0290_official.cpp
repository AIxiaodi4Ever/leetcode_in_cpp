class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<string, char> wordTOpattern;
        unordered_map<char, string> patternTOword;
        int m = s.length();
        int i = 0;
        for (const char &ch : pattern)
        {
            if (i >= m)
                return false;
            int j = i;
            while (j < m && s[j] != ' ') ++j;
            const string &tmp = s.substr(i, j - i);
            if (wordTOpattern.count(tmp) && wordTOpattern[tmp] != ch)
                return false;
            if (patternTOword.count(ch) && patternTOword[ch] != tmp)
                return false;
            wordTOpattern[tmp] = ch;
            patternTOword[ch] = tmp;
            i = j + 1;
        }
        return i > m;
    }
};