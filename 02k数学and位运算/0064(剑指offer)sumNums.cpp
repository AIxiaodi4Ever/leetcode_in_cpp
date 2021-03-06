// 剑指offer：64
// 看到评论里法向有结合方法一和方法二的方法

int quick_multi(int n1, int n2, int ans)
{
    n2 && (((n2 & 1) && (ans += n1) && (ans = quick_multi(n1 << 1, n2 >>1, ans))) || (ans = quick_multi(n1 << 1, n2 >> 1, ans)));
    return ans;
    
}

int sumNums(int n)
{
    int ans = 0;
    return quick_multi(n, n + 1, ans) >> 1;
}