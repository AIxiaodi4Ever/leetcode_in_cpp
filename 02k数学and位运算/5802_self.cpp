class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    
    long long pow(int num, long long n) {
        if (n == 0) {
            return 1;
        } 
        if (n == 1) {
            return num;
        }
        
        long long half = pow(num, n / 2) % MOD;
        if (n % 2 == 0) {
            return half * half % MOD;
        }
        else {
            return num * half * half % MOD;
        }
    }
    
    int countGoodNumbers(long long n) {
        long long ans = 1;
        ans = pow(5, (long double)n / 2 + 0.5) * pow(4, n / 2) % MOD;
        return ans;
    }
};