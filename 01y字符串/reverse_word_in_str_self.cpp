#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ˼·����ȥ��ǰ��Ŀո�֮��ת�����ַ���
// ��ͷ�����ַ�������תÿһ�����ʣ��ڼ�ȥ�����ʼ����Ŀո�
// ���һ��������ѭ������֮��ת

void reverse(char *s, int start, int end)
{
    char temp;
    while (start < end)
    {
        temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

void delete_extra(char *s, int pos)
{
    do{
        s[pos] = s[pos + 1];
        pos++;
    } while (s[pos]);

}

char *reverseWords(char *s)
{
    int len;
    // ȥ��ǰ��Ŀո�
    while (*s == ' ')
    {
        s++;
    }

    len = strlen(s) - 1;
    // ��ֹ����Ϊ��
    if (len < 0)
    {
        return s;
    }
    // ȥ������Ŀո�
    while (s[len] == ' ')
    {
        s[len--] = '\0';
    }

    // ��ת�����ַ���
    reverse(s, 0, len);

    // ��תÿһ������
    int index = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            reverse(s, index, i - 1);
        
            // ɾ������Ŀո�
            while (s[i+1] == ' ')
            {
                delete_extra(s, i + 1);
                len--;
            }
            index = i + 1;
        }
    }
    // ��ת���ĵ���
    reverse(s, index, len);
    return s;
}