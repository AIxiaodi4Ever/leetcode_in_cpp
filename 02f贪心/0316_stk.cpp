class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26, 0), freq(26, 0);
        for (char& c : s)
            ++freq[c - 'a'];

        string stk;
        for (const char &c : s)
        {
            if (!vis[c - 'a'])
            {
                while (!stk.empty() && c < stk.back())
                {
                    if (freq[stk.back() - 'a'] > 0)
                    {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    }
                    else
                        break;
                }
                vis[c - 'a'] = 1;
                stk.push_back(c);
            }
            --freq[c - 'a'];
        }
        return stk;
    }
};