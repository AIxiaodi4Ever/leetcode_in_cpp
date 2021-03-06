// 25，10，5，1四种硬币表示大小为n的数有几种表示方法
// 解题思路：等差数列
// 假设有i个25美分，则剩余r=n-25*i，r = 10*a + 5*b + c;
// 另a0 = floor(r/10)，c0 < 5, 则b也可以达到最大值b0;
// 当取a = x时，剩下的金额为：10 * (a0 - x) + 5*b0 + c0;
// 把10 * (a0-x)用5美分表示则：5 * (2a0 - 2x0 + b0) + c0;
// 则五美分的取值范围为：[0, 2a0+b0-2x];
// 对x=[0,a0]求和，结果为：(2a0+b0+1 + b0+1) * (a0+1)/2=(a0+b0+1)(a0+1);
// 枚举i并对上式求和即可

#define MOD 1000000007

int waysToChange(int n)
{
    int ans = 0;
    int a0, b0, rest;
    for (int i = 0; i <= n / 25; i++)
    {
        rest = n - 25 * i;
        a0 = rest / 10;
        b0 = rest % 10 / 5;
        ans = (ans + (long long)(a0 + b0 + 1) * (a0 + 1) % MOD) % MOD;
    }

    return ans;
}