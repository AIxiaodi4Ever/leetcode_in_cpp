/* �����⣺64 (xxx���Ա���)*/
/*�� 1+2+...+n ��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����*/

// ����һ��ʹ��(n && (n += sumNums(n - 1)); return n;)����(return n == 0 ? 0 : n + sumNums(n - 1));

// �����������ٳˣ�����͹�ʽ (n+1)*(n)/2 �еĳ˷��ӷ����棬���������ƴ��档
/* 
���ٳˣ��������£�
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
������Ȼʹ����ѭ������û�а취ȥ�����ѭ������أ������еģ��Ǿ����Լ��ֶ�չ������Ϊ��Ŀ���ݷ�Χ nnn Ϊ
 [1,10000]���� nnn ������չ����಻�ᳬ�� 14λ�������ֶ�չ�� 14�����ѭ�����ɣ�������������Ŀ
 ��Ҫ�󣬾���ʵ�ֿ��Բο���������Ĵ��롣
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

// ���������﷨���н�Ϸ���һ�ͷ�������c++����
// �Լ�д��c���Ե�
int quick_multi(int n1, int n2, int ans)
{
    // ���n2Ϊ0������ans
    // ���n2��Ϊ0���ж��Ƿ�(n2 & 1)�����(n2&1)����ans = ans + n1
    // ����(n2 & 1)�Ƿ��������Ҫ����ans = quick_multi(n1 << 1, n2 >> 1, ans);
    n2 && (((n2 & 1) && (ans += n1) && (ans = quick_multi(n1 << 1, n2 >>1, ans))) || (ans = quick_multi(n1 << 1, n2 >> 1, ans)));
    return ans;
    
}

int sumNums(int n)
{
    int ans = 0;
    return quick_multi(n, n + 1, ans) >> 1;
}