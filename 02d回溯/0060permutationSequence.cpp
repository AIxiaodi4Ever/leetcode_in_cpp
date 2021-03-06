class Solution {
public:
    string getPermutation(int n, int k) 
    {
        vector<int> factorial(n);
        factorial[0] = 1;
        // 这里应该从1开始，我又错写成从0开始了。。
        for (int i = 1; i < n; ++i)
        {
            // * 我写错成 +
            factorial[i] = i * factorial[i - 1];
        }

        string ans;
        --k;
        vector<int> valid(n + 1, 1);
        for (int i = 1; i <= n; ++i)
        {
            // 本身就是向下取整，不需要floor
            int order = k / factorial[n - i] + 1;
            for (int j = 1; j <= n; ++j)
            {
                order -= valid[j];
                if (!order)
                {
                    ans += (j + '0');
                    valid[j] = 0;
                    // 忘记break。。
                    break;
                }
                // 忘记更新k
                k = k % factorial[n - i];
            }
        }
        return ans;
    }
};