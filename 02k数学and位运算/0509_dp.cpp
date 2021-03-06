class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;


        int last = 0, prev = 0, cur = 1;
        for (int i = 2; i <= n; ++i)
        {
            last = prev;
            prev = cur;
            cur = last + prev;
        }
        return cur;
    }
};