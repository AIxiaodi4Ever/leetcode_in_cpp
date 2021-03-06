/* Leetcode:925
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, 
the key might get long pressed, and the character will be typed 1 or more times.
You examine the typed characters of the keyboard.  Return True if it is possible that 
it was your friends name, with some characters (possibly none) being long pressed.

Example 1:
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:
Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.

Example 3:
Input: name = "leelee", typed = "lleeelee"
Output: true

Example 4:
Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.

Constraints:

    1 <= name.length <= 1000
    1 <= typed.length <= 1000
    The characters of name and typed are lowercase letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/long-pressed-name
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路
// 把连续出现的字符看做字符块，如果typed中字符块的顺序与name相同，
// 并且字符块中字符数量大于等于name对应的字符块，则返回true
// 利用指针，当p_name与p_typed指向的字符相同时，同时下移；
// 不同时，如果p_typed指向的字符不等于p_name上一次指向的字符，返回false；
// 不同时，如果p_typed指向的字符等于p_name上一次指向的字符，则p_type下移；
// 当name遍历结束时，返回true；

bool isLongPressedName(char * name, char * typed)
{
    int n_length, t_length;
    char *p_name, *p_typed;
    int i = 1, j = 1;

    n_length = strlen(name);
    t_length = strlen(typed);
    p_name = name;
    p_typed = typed;

    // name比typed长或第一个字符就不同则返回false
    if (n_length > t_length || p_name[0] != p_typed[0])
        return false;

    while(i < n_length)
    {
        // name未遍历完时，type已经遍历结束，则返回false
        if (j == t_length)
            return false;

        // 指向的字符不相等
        if (p_name[i] != p_typed[j])
        {
            // p_typed与p_name的上一个指向不同时，返回false
            if (p_name[i - 1] != p_typed[j])
                return false;
            // 相同时，j++    
            else
                j++;
        }

        // 指向字符相等，i++, j++
        if (p_name[i] == p_typed[j])
        {
            i++;
            j++;
        }
    }

    // name遍历完但typed仍未遍历完，则检查typed后面的字符是否等于name的最后字符
    while (j < t_length)
    {
        if(p_typed[j] != p_name[n_length - 1])
            return false;
        else
            j++;
    }

    // name与typed全部遍历完，并且条件满足，返回true
    return true;
}