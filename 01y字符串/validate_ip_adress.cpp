/*
*   Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
*   IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers,
each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

*   IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits.
The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334
is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters
in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading
zeros and using upper cases).
*   However, we don't replace a consecutive group of zero value with a single empty group using two consecutive 
colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
*   Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 
is invalid.

*   Note: You may assume there is no extra space or special characters in the input string. 
*/

/* ����˼·����ȫ��̰��~~~~~
һ��ʼ����Ϊ�е����ipv4 �������� ipv6 ����Ȼ��û��ûð�ŵ�������~~~
һ·�ϣ����Ǹ��ֿӣ���˵�ˣ���Ŀ���㣬�Լ�ľګ~~~

��֮v4 v6�������Դ���
ÿ��ȥȡһ������������һ��������Ҫ���ֹͣ��v4 4���Σ�v6 8���ζ�����Ҫ��������Ϊok~~~

���������Ŵ���Ĳ��������Ź����ģ�Ҫ��û��������ÿӶ��~~~
Ϊʲô��ô��~~~����ϰ��

���ߣ�cue-3
���ӣ�https://leetcode-cn.com/problems/validate-ip-address/solution/fu-bu-fu-za-jiu-kan-yong-li-diao-bu-diao-zuan-zhe-/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע�������� */

#include <string.h>
#include <stdlib.h>
#include <memory.h>

char retStr[3][8] = {"IPv4", "IPv6", "Neither"};

bool containDot(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '.') {
            return true;
        }
    }

    return false;
}

bool containColon(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == ':') {
            return true;
        }
    }

    return false;
}

int findDotPos(char *s, int seq)
{
    int len = strlen(s);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if ((s[i] == '.') && (i != 0) && (i != len - 1)) {
            cnt++;
            
            if (cnt == seq) {
                return i;
            }
        }
    }

    return -1;
}

bool isZeroChar(char c)
{
    if (c == '0') {
        return true;
    }
    return false;
}

bool isValidV4Num(int num)
{
    if ((num >= 0) && (num <= 255)) {
        return true;
    }
    return false;
}

bool intStrValidCheck(char *tmp)
{
    int len = strlen(tmp);
    if (len <= 0 || len > 3) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(tmp[i])) {
            return false;
        }
    }

    int num = atoi(tmp);
    if (!isValidV4Num(num)) {
        return false;
    }

    if (num == 0 && tmp[1] == '0') {
        return false;
    }

    if (num != 0 && tmp[0] == '0') {
        return false;
    }

    return true;
}

char *ipV4Process(char *ip)
{
    int start = 0;
    int end = 0;
    int pos = -1;
    for (int i = 0; i < 4; i++) {
        start = pos + 1;
        pos = findDotPos(ip, i + 1);
        end = pos - 1;
        if (i == 3) {
            end = strlen(ip) - 1;
        } else if (pos == -1) {
            return retStr[2];
        }

        char tmp[128] = {0};
        if ((end - start + 1) <= 0 || (end - start + 1) > 3) {
            return retStr[2];
        }
        (void)memcpy(tmp, ip + start, end - start + 1);

        if (!intStrValidCheck(tmp)) {
            return retStr[2];
        }
    }

    return retStr[0];
}

int findColonPos(char *s, int seq)
{
    int len = strlen(s);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if ((s[i] == ':') && (i != 0) && (i != len - 1)) {
            cnt++;
            
            if (cnt == seq) {
                return i;
            }
        }
    }

    return -1;
}

bool isValidChar(c) {
    if ((c >= 'a' && c <= 'f') ||
        (c >= 'A' && c <= 'F')) {
            return true;
    }
    return false;
}

bool v6intStrValidCheck(char *tmp)
{
    int len = strlen(tmp);
    if (len <= 0 || len > 4) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (!(isdigit(tmp[i]) || isValidChar(tmp[i]))) {
            return false;
        }
    }

    return true;
}

char *ipV6Process(char *ip)
{
    int start = 0;
    int end = 0;
    int pos = -1;
    for (int i = 0; i < 8; i++) {
        start = pos + 1;
        pos = findColonPos(ip, i + 1);
        end = pos - 1;

        if (i == 7) {
            end = strlen(ip) - 1;
        }

        if (end < 0) {
            return retStr[2];
        }

        if ((end - start + 1) <= 0 || (end - start + 1) > 4) {
            return retStr[2];
        }

        char tmp[128] = {0};
        (void)memcpy(tmp, ip + start, end - start + 1);

        if (!v6intStrValidCheck(tmp)) {
            return retStr[2];
        }
    }
    return retStr[1];
}

char * validIPAddress(char * IP)
{
    if (IP == NULL) {
        return IP;
    }

    if (containDot(IP)) {
        return ipV4Process(IP);
    } else if (containColon(IP)){
        return ipV6Process(IP);
    } else {
        return retStr[2];
    }
}