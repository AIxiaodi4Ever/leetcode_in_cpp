#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 思路：先去除前后的空格，之后反转整个字符串
// 从头遍历字符串并反转每一个单词，期间去除单词间多余的空格
// 最后一个单词在循环结束之后反转

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
    // 去除前面的空格
    while (*s == ' ')
    {
        s++;
    }

    len = strlen(s) - 1;
    // 防止输入为空
    if (len < 0)
    {
        return s;
    }
    // 去除后面的空格
    while (s[len] == ' ')
    {
        s[len--] = '\0';
    }

    // 反转整个字符串
    reverse(s, 0, len);

    // 反转每一个单词
    int index = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            reverse(s, index, i - 1);
        
            // 删除多余的空格
            while (s[i+1] == ' ')
            {
                delete_extra(s, i + 1);
                len--;
            }
            index = i + 1;
        }
    }
    // 反转最后的单词
    reverse(s, index, len);
    return s;
}