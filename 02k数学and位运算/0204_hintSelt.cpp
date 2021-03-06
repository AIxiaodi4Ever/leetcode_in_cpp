class Solution {
public:
    // less than n, not less equal than n
    int countPrimes(int n) 
    {
        vector<bool> isPrime(n, true);
        // use i * i < n instead of i < sqrt(n) to avoid calling an expensive sqrt()
        for (int i = 2; i * i < n; ++i)
        {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }

        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i])
                ++ans;
        }
        return ans;
    }
};