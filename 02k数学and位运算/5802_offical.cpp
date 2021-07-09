class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    
    int countGoodNumbers(long long n) {
        auto quickPow = [](int x, long long y)->int {
            int ret = 1, mul = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    ret = (long long)ret * mul % MOD;
                }
                mul = (long long)mul * mul % MOD;
                y /= 2;
            }
            return ret;
        };

        return (long long)quickPow(5, (n + 1) / 2) * quickPow(4, n / 2) % MOD;
    }
};