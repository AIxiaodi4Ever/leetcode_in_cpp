// leetcode:541
/* description:
 *Given a string and an integer k, you need to reverse the first k characters for every 2k 
  characters counting from the start of the string. If there are less than k characters left,
  reverse all of them. If there are less than 2k but greater than or equal to k characters, 
  then reverse the first k characters and left the other as original.

Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:
    The string consists of lower English letters only.
    Length of the given string and k will in the range [1, 10000]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *  
*/

// 解题思路：
// 从0，2k，4k...的位置开始，反转前k个字符。
// 如果从某个位置开始，之后的字符串数目小于k，则反转其后的所以字符；
// 如果某个位置大于字符串的长度，则说明该字符串已经遍历结束；
char * reverseStr(char * s, int k)
{
    int length = strlen(s);
    int position = 0;
    int left, right;

    if (s == NULL)
        return NULL;

    while (position <= length)
    {
        left = position;
        // 即 (position + k - 1) > (length - 1);
        if ((position + k) > length)
            right = length - 1;
        else
            right = position + k - 1;
        
        // 反转
        // 这里改变了s，想保留s则再声明一个字符指针
        while (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }

        position += 2 * k;
    }

    return s;
}