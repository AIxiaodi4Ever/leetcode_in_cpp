class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char, string> pTOw;
        unordered_map<string, char> wTOp;
        istringstream is(s);
        for (const char &c : pattern)
        {
            string word;
            if (!(is >> word))
                return false;
            if (!pTOw.count(c) && !wTOp.count(word))
            {
                pTOw[c] = word;
                wTOp[word] = c;
            }
            else if (pTOw[c] != word || wTOp[word] != c)
                return false;
        }
        string word;
        if (is >> word)
            return false;
        return true;
    }
};