class Solution {
public:
    int calculate(string s) 
    {
        vector<int> stk;
        char preSign = '+';
        int n = s.size();

        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0');  // 必须得把s[i]-'0'括起来，否则先+s[i]可能导致越界
            // 不能用else if否则会忽略表达式最后的数
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1)
            {
                switch (preSign)
                {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }// i
        return accumulate(stk.begin(), stk.end(), 0);
    }
};