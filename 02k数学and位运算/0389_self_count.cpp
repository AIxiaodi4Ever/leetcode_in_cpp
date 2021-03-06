class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);
        int length = s.length();
        for (int i = 0; i < length; ++i)
        {
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }
        --freq[t[length] - 'a'];
        for (int i = 0; i < 26; ++i)
        {
            if (freq[i] == -1)
                return 'a' + i; 
        }
        return ' ';
    }   
};