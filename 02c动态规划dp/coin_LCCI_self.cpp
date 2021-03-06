// 25，10，5，1四种硬币表示大小为n的数有几种表示方法

// 解题思路：
// 动态规划：f(i,v) = f(i-1， v) + f(i - 1, v - ci) + ... + f(i - 1, v - k * ci)
// 其中f(i,v)表示用前i个硬币表示大小为v的数的取法，i表示前i个硬币，题中i = 4， v = [0, n],有n+1中可能，k = floor(v/ci)
// f(i, v-ci) = f(i - 1, v - ci) + f(i-1, v- 2 * ci) + ... + f(i - 1. v-k*ci)
// 所以得到简化的动态规划表达式：f(i,v) = f(i-1,v) + f(i,v-ci)
// 使用滚动数组思想，外层循环为i=0~4内层循环为j=coin[i]~n
// 计算i之前，数组dp保存的是f(i-1,v')，计算i的每一个位置j时，dp[1]~dp[j-1]表示f(i,v')，dp[j]~dp[n]表示f(i-1,v')。
// 其中v'属于[0, v]
// 所以dp[j] = dp[j] + dp[j-coin[i]]

#define MOD 1000000007;

int coins[4] = {1, 5, 10, 25};

//【算法思路】dp。
int waysToChange(int n)
{
    int coin;
    int *dp = (int *)calloc(n + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 0; i < 4; i++)
    {
        coin = coins[i];
        for (int j = coin; j <= n; j++)
        {
            dp[j] = (dp[j] + dp[j - coin]) % MOD;
        }
    }

    return dp[n];
}