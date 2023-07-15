class Solution {
public:
    const int mod = 1e9 + 7;
    int numWays(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 2;
        for (int i = 3; i <= n; ++i) {
            int temp = b;
            b = (a + b) % mod;
            a = temp;
        }
        return b;
    }
};