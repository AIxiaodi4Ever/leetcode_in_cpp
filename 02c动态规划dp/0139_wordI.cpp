class Solution {
public:
    unordered_set<string> dict;

    bool wordBreak(string s, vector<string>& wordDict) 
    {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        int Length = s.length();
        vector<bool> dp(Length + 1);
        dp[0] = true;
        for (int i = 1; i <= Length; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                string word = s.substr(j, i - j);
                if (dp[j] && dict.count(word))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[Length];
    }

};