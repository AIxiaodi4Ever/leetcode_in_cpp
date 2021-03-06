/*leetcode:009*/
/*
description:
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:
Coud you solve it without converting the integer to a string?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/palindrome-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·����ת��һ�������
// 1.���ȣ������ͳ�0��������и�λΪ0��������flase;
// 2.x��10ȡ������Ȼ��x����10���ظ���һ���̣����õ������������Ⱥ�˳��:reverse = rem1 + 10 * rem2 + 100 * ...
// 3.�����������У�reverse = x�� ��˵����ת��һ�����ֵ�������˳���ǰһ�����ֵĴ�С��˵���ǻ��ģ�����true;
// 4.���������̳���reverse > x,�򷵻�false
bool isPalindrome(int x)
{

    int reverse = 0;

    if (x < 0 || (x != 0 && x % 10 == 0))
        return false;

    // ����x��λ��
    while (x > reverse)
    {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }

    // x������ʱ���м����ֲ�Ӱ������ԣ����ͨ������10ȥ��
    return (x == reverse) || (x == reverse / 10);
}