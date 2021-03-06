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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-string-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 *  
*/

// ����˼·��
// ��0��2k��4k...��λ�ÿ�ʼ����תǰk���ַ���
// �����ĳ��λ�ÿ�ʼ��֮����ַ�����ĿС��k����ת���������ַ���
// ���ĳ��λ�ô����ַ����ĳ��ȣ���˵�����ַ����Ѿ�����������
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
        // �� (position + k - 1) > (length - 1);
        if ((position + k) > length)
            right = length - 1;
        else
            right = position + k - 1;
        
        // ��ת
        // ����ı���s���뱣��s��������һ���ַ�ָ��
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