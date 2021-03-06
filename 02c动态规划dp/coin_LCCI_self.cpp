// 25��10��5��1����Ӳ�ұ�ʾ��СΪn�����м��ֱ�ʾ����

// ����˼·��
// ��̬�滮��f(i,v) = f(i-1�� v) + f(i - 1, v - ci) + ... + f(i - 1, v - k * ci)
// ����f(i,v)��ʾ��ǰi��Ӳ�ұ�ʾ��СΪv������ȡ����i��ʾǰi��Ӳ�ң�����i = 4�� v = [0, n],��n+1�п��ܣ�k = floor(v/ci)
// f(i, v-ci) = f(i - 1, v - ci) + f(i-1, v- 2 * ci) + ... + f(i - 1. v-k*ci)
// ���Եõ��򻯵Ķ�̬�滮���ʽ��f(i,v) = f(i-1,v) + f(i,v-ci)
// ʹ�ù�������˼�룬���ѭ��Ϊi=0~4�ڲ�ѭ��Ϊj=coin[i]~n
// ����i֮ǰ������dp�������f(i-1,v')������i��ÿһ��λ��jʱ��dp[1]~dp[j-1]��ʾf(i,v')��dp[j]~dp[n]��ʾf(i-1,v')��
// ����v'����[0, v]
// ����dp[j] = dp[j] + dp[j-coin[i]]

#define MOD 1000000007;

int coins[4] = {1, 5, 10, 25};

//���㷨˼·��dp��
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