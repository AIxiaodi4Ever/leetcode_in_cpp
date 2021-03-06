class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        vector<char> stk;
        for (const char& dight : num)
        {
            while (!stk.empty() && stk.back() > dight && k)
            {
                stk.pop_back();
                --k;
            }
            stk.push_back(dight);
        }
        for (; k > 0; --k)
            stk.pop_back();
        string ans = "";
        bool LeadingZero = true;
        for (const char & digit : stk)
        {
            if (LeadingZero && digit == '0')
                continue;
            ans += digit;
            LeadingZero = false;
        }
        return ans == "" ? "0" : ans;
    }
};