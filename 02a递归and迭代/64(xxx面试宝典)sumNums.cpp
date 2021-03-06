/* 面试题：64 (xxx面试宝典)*/
/*求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。*/

// 方法一，使用(n && (n += sumNums(n - 1)); return n;)代替(return n == 0 ? 0 : n + sumNums(n - 1));

// 方法二，快速乘，将求和公式 (n+1)*(n)/2 中的乘法加法代替，除法用右移代替。
/* 
快速乘，代码如下：
int quickMulti(int A, int B) {
    int ans = 0;
    for ( ; B; B >>= 1) {
        if (B & 1) {
            ans += A;
        }
        A <<= 1;
    }
    return ans;
}
但是仍然使用了循环，有没有办法去掉这个循环语句呢？答案是有的，那就是自己手动展开，因为题目数据范围 nnn 为
 [1,10000]所以 nnn 二进制展开最多不会超过 14位，我们手动展开 14层代替循环即可，至此满足了题目
 的要求，具体实现可以参考下面给出的代码。
class Solution {
public:
    int sumNums(int n) {
        int ans = 0, A = n, B = n + 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        return ans >> 1;
    }
};
 */

// 看到评论里法向有结合方法一和方法二的c++方法
// 自己写了c语言的
int quick_multi(int n1, int n2, int ans)
{
    // 如果n2为0，返回ans
    // 如果n2不为0，判断是否(n2 & 1)，如果(n2&1)计算ans = ans + n1
    // 无论(n2 & 1)是否成立，都要计算ans = quick_multi(n1 << 1, n2 >> 1, ans);
    n2 && (((n2 & 1) && (ans += n1) && (ans = quick_multi(n1 << 1, n2 >>1, ans))) || (ans = quick_multi(n1 << 1, n2 >> 1, ans)));
    return ans;
    
}

int sumNums(int n)
{
    int ans = 0;
    return quick_multi(n, n + 1, ans) >> 1;
}