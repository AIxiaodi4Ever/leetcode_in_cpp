/***********************************************************************************
 * 题目描述：
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

// 解题思路：题解里有两个浏览高的解法，一个是使用链表实现栈，遇到‘[’时，将其内部的字符串入栈，
// 遇到']'时，将栈顶的字符串取出，并将其赋值digits遍，放入新栈顶字符串的后面
// ************************************************************************************
// 这里使用另一种递归求解法，每次遇到数字时更新count值，遇到字符时，放入本次递归中字符数组ret后面，
// 遇到'['进行递归，每次递归结束之后，将该次递归中的字符串复制digits遍，加入上一递归中字符数组ret
// 后面，并更新字符指针s的位置。

/* 更新s的位置时使用了指针指针，因为传递指针只是将其内容复制到新的函数，函数结束时原本的指针内容不变。*/

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
            // 利用ASCII差值计算count
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
            // 更新s的位置
            s = end;
        }
        else if(*s == ']')
        {
            ret[idx] = '\0';
            // 记录s当前的位置
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
