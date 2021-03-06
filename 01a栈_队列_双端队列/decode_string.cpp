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

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

typedef struct SNode* PtrToSNode;
struct SNode {
    char* str;
    PtrToSNode next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->str = NULL;
    S->next = NULL;
    return S;
}

bool Add(Stack S)
{
    PtrToSNode tmp = (PtrToSNode)malloc(sizeof(struct SNode));
    tmp->str = (char*)malloc(3000*sizeof(char));
    memset(tmp->str, '\0', 3000*sizeof(char));
    tmp->next = S->next;
    S->next = tmp;
    return true;
}

bool IsEmpty(Stack S)
{
    return (S->next == NULL);
}

char* Top(Stack S)
{
    if (IsEmpty(S)) {
        return NULL;
    }
    PtrToSNode firstnode = S->next;
    return firstnode->str;
}

bool Pop(Stack S)
{
    if (IsEmpty(S)) {
        return false;
    }
    PtrToSNode firstnode = S->next;
    S->next = firstnode->next;
    firstnode->next = NULL;
    free(firstnode);
    return true;
}


char * decodeString(char * s){
    int sLen = strlen(s);
    //用来记录倍数关系的
    int* times = (int*)malloc(50*sizeof(int));
    memset(times, 0, 50*sizeof(int));
    int timesLen = 0;
    // 用来转换成int
    char* time = (char*)malloc(11*sizeof(char));
    memset(time, '\0', 11*sizeof(char));
    
    Stack S = CreateStack();
    Add(S);
    
    for (int i = 0; i < sLen; i++) {
        if (isdigit(s[i])) {
            time[strlen(time)] = s[i];
        }
        else if (s[i] == '[') {
            int count = atoi(time);
            memset(time, '\0', 11*sizeof(char));
            times[timesLen] = count;
            timesLen++;
            Add(S);
        }
        else if (isalpha(s[i])) {
            Top(S)[strlen(Top(S))] = s[i];
        }
        else if (s[i] == ']') {
            char* str = (char*)malloc(3000*sizeof(char));
            memset(str, '\0', 3000*sizeof(char));
            strcpy(str, Top(S));
            Pop(S);
            int strcount = times[timesLen - 1];
            //printf("%d\n",strcount);
            times[timesLen - 1] = 0;
            timesLen--;
            for (int i = 0; i < strcount; i++) {
                strcat(Top(S), str);
            }
        }
        //printf("%d\n",i);
        //puts(Top(S));
    }
    return Top(S);
}

/*  
作者：xiaohuzai
链接：https://leetcode-cn.com/problems/decode-string/solution/cshou-xie-zhan-chao-guo-shuang-bai-by-xiaohuzai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/