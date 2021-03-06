/* leetcode:67 */
/*
 Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
    Each string consists only of '0' or '1' characters.
    1 <= a.length, b.length <= 10^4
    Each string is either "0" or doesn't contain any leading zero.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/add-binary
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·
// ģ�⡰����ʽ���ļӷ�����
// 1. ��ת�ַ���a��b�Ա����Сλ��ʼ��ӣ�ʹ��n����a��b���ȵ����ֵ��
// 2. ʹ��carry����ÿһλ��ӵĽ���������ý����2���࣬��ֵ����Ӧ��ans[len]��
// 3. carry /= 2��ʹcarry������λ��������һλ���ļӷ�
// 4. �������������λ����Ӻ�carry / 2�Ľ����Ϊ0��˵����Ȼ���ڽ�λ����ans[len++] = '1'������ʹans[len] = '\0'��

#define max(a,b)  (((a) > (b)) ? (a) : (b))

void reverse(char *s)
{
    int len = strlen(s);

    // iһ��ҪС��len / 2������len������
    for (int i = 0; i < len / 2; i++)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

char * addBinary(char * a, char * b)
{
    reverse(a);
    reverse(b);

    int len_a = strlen(a);
    int len_b = strlen(b);
    int n = max(len_a, len_b);
    int carry = 0, len = 0;

    char *ans = (char *)malloc(sizeof(char) * (n + 2));

    for (int i = 0; i < n; i++)
    {
        carry += i < len_a ? (a[i] == '1') : 0;
        carry += i < len_b ? (b[i] == '1') : 0;

        ans[len++] = carry % 2 + '0';

        carry /= 2;
    }   

    if (carry)
    {
        ans[len++] = '1';
    }
    ans[len] = '\0';

    reverse(ans);

    return ans;
}