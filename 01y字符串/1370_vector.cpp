class Solution {
public:
    string sortString(string s) 
    {
        vector<int> nums(26, 0);
        for (const char &c : s)
            ++nums[c - 'a'];
        string ret;
        while (ret.length() < s.length())
        {
            for (int i = 0; i < 26; ++i)
            {
                if (nums[i])
                {
                    ret.push_back('a' + i);
                    --nums[i];
                }
            }
            for (int i = 25; i >= 0; --i)
            {
                if (nums[i])
                {
                    ret.push_back('a' + i);
                    --nums[i];
                }
            }
        }
        return ret;
    }
};