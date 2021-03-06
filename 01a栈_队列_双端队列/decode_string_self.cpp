/***********************************************************************************
 * ��Ŀ������
* Given an encoded string, return its decoded string.
* The encoding rule is: k[encoded_string], where the encoded_string inside the 
square brackets is being repeated exactly k times. Note that k is guaranteed 
to be a positive integer.
* You may assume that the input string is always valid; No extra white spaces,
square brackets are well-formed, etc.
* Furthermore, you may assume that the original data does not contain any digits 
and that digits are only for those repeat numbers, k. For example, there won't be 
input like 3a or 2[4].

Example:
* s = "3[a]2[bc]", return "aaabcbc".
* s = "3[a2[c]]", return "accaccacc".
* s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
***********************************************************************************/

// ����˼·�����������������ߵĽⷨ��һ����ʹ������ʵ��ջ��������[��ʱ�������ڲ����ַ�����ջ��
// ����']'ʱ����ջ�����ַ���ȡ���������丳ֵdigits�飬������ջ���ַ����ĺ���
// ************************************************************************************
// ����ʹ����һ�ֵݹ���ⷨ��ÿ����������ʱ����countֵ�������ַ�ʱ�����뱾�εݹ����ַ�����ret���棬
// ����'['���еݹ飬ÿ�εݹ����֮�󣬽��ôεݹ��е��ַ�������digits�飬������һ�ݹ����ַ�����ret
// ���棬�������ַ�ָ��s��λ�á�

/* ����s��λ��ʱʹ����ָ��ָ�룬��Ϊ����ָ��ֻ�ǽ������ݸ��Ƶ��µĺ�������������ʱԭ����ָ�����ݲ��䡣*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>
*/

//char *decodeStringCore(char *s, char **e);

#define MAX_LEN 3000

char *decodeStringCore(char *s, char **e)
{
    char *ret = (char *)malloc(sizeof(char) * MAX_LEN);
    char *buf, *end = NULL;
    int count = 0, idx = 0;

    while (*s != '\0')
    {
        if (isdigit(*s))
        {
            // ����ASCII��ֵ����count
            count = 10 * count + *s - '0';
        }
        else if(isalpha(*s))
        {
            ret[idx++] = *s;
        }
        else if(*s == '[')
        {
            buf = decodeStringCore(s + 1, &end);
            while (count)
            {
                strcpy(ret + idx, buf);
                idx += strlen(buf);
                count--;
            }
            // ����s��λ��
            s = end;
        }
        else if(*s == ']')
        {
            ret[idx] = '\0';
            // ��¼s��ǰ��λ��
            *e = s;
            return ret;
        }
        s++;
    }

    ret[idx] = '\0';
    return ret;
}

char * decodeString(char * s)
{
    char *end = NULL;
    return decodeStringCore(s, &end);
}
