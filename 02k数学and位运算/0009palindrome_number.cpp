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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路：反转后一般的数字
// 1.首先，负数和除0以外的所有个位为0的数返回flase;
// 2.x对10取余数，然后x除以10，重复这一过程，将得到的余数按照先后顺序:reverse = rem1 + 10 * rem2 + 100 * ...
// 3.如果运算过程中，reverse = x， 则说明反转的一般数字等于正常顺序的前一半数字的大小，说明是回文，返回true;
// 4.如果运算过程出现reverse > x,则返回false
bool isPalindrome(int x)
{

    int reverse = 0;

    if (x < 0 || (x != 0 && x % 10 == 0))
        return false;

    // 计算x的位数
    while (x > reverse)
    {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }

    // x是奇数时，中间数字不影响回文性，因此通过除以10去除
    return (x == reverse) || (x == reverse / 10);
}