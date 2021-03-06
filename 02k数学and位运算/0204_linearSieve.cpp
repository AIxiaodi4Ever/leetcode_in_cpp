class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        vector<int> Primes;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i])
                Primes.push_back(i);
            for (int j = 0; j < Primes.size() && i * Primes[j] < n; ++j)
            {
                isPrime[i * Primes[j]] = 0;
                if (i % Primes[j] == 0)
                    break;
            }
        }
        return Primes.size();
    }
};