/* 
 错误，这里不能用for循环，因为内部计算num时最后有i++，如果
 使用for循环，会导致i再次+1，因此会略过某些正负号，导致结果错误
*/
class Solution {
public:
    int calculate(string s) 
    {
        stack<int> ops;
        ops.push(1);
        int sign = 1;
        int ret = 0;

        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == ' ')
                ;
            else if (s[i] == '+')
            {
                sign = ops.top();
            }
            else if (s[i] == '-')
            {
                sign = -ops.top();
            }
            else if (s[i] == '(')
            {
                ops.push(sign);
            }
            else if (s[i] == ')')
            {
                ops.pop();
            }
            else
            {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};