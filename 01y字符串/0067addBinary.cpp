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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路
// 模拟“列竖式”的加法方法
// 1. 反转字符串a和b以便从最小位开始相加，使用n保留a，b长度的最大值；
// 2. 使用carry保留每一位相加的结果，并将该结果与2求余，赋值给对应的ans[len]；
// 3. carry /= 2，使carry保留进位，参与下一位数的加法
// 4. 如果计算完所有位数相加后，carry / 2的结果不为0，说明仍然存在进位，另ans[len++] = '1'，并且使ans[len] = '\0'；

#define max(a,b)  (((a) > (b)) ? (a) : (b))

void reverse(char *s)
{
    int len = strlen(s);

    // i一定要小于len / 2而不是len。。。
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