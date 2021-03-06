class Solution {
public:
    int monotoneIncreasingDigits(int N) 
    {
        string strN = to_string(N);
        int i = 1;
        for (; i < strN.size() && strN[i] >= strN[i - 1]; ++i) ;
        if (i < strN.size())
        {
            while (i > 0 && strN[i - 1] > strN[i])
            {
                strN[i - 1] -= 1;
                i -= 1;
            }
            for (i += 1; i < strN.size(); ++i)
                strN[i] = '9';
        }
        return stoi(strN);
    }
};