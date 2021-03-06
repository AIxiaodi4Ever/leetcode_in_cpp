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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/long-pressed-name
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·
// ���������ֵ��ַ������ַ��飬���typed���ַ����˳����name��ͬ��
// �����ַ������ַ��������ڵ���name��Ӧ���ַ��飬�򷵻�true
// ����ָ�룬��p_name��p_typedָ����ַ���ͬʱ��ͬʱ���ƣ�
// ��ͬʱ�����p_typedָ����ַ�������p_name��һ��ָ����ַ�������false��
// ��ͬʱ�����p_typedָ����ַ�����p_name��һ��ָ����ַ�����p_type���ƣ�
// ��name��������ʱ������true��

bool isLongPressedName(char * name, char * typed)
{
    int n_length, t_length;
    char *p_name, *p_typed;
    int i = 1, j = 1;

    n_length = strlen(name);
    t_length = strlen(typed);
    p_name = name;
    p_typed = typed;

    // name��typed�����һ���ַ��Ͳ�ͬ�򷵻�false
    if (n_length > t_length || p_name[0] != p_typed[0])
        return false;

    while(i < n_length)
    {
        // nameδ������ʱ��type�Ѿ������������򷵻�false
        if (j == t_length)
            return false;

        // ָ����ַ������
        if (p_name[i] != p_typed[j])
        {
            // p_typed��p_name����һ��ָ��ͬʱ������false
            if (p_name[i - 1] != p_typed[j])
                return false;
            // ��ͬʱ��j++    
            else
                j++;
        }

        // ָ���ַ���ȣ�i++, j++
        if (p_name[i] == p_typed[j])
        {
            i++;
            j++;
        }
    }

    // name�����굫typed��δ�����꣬����typed������ַ��Ƿ����name������ַ�
    while (j < t_length)
    {
        if(p_typed[j] != p_name[n_length - 1])
            return false;
        else
            j++;
    }

    // name��typedȫ�������꣬�����������㣬����true
    return true;
}