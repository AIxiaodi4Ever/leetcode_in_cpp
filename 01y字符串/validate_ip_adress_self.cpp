/*  ��Ŀ������
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

// ����˼·��
// 1. ���ж��ַ����Ƿ�ֻ��3���㣬��7��ð�ţ�ǰ�߿���ΪIPV4������0�����߿���ΪIPV6������1��������ΪNeither����2��
// 2. �������0�������ж��Ƿ�ΪIPV4�����򷵻�0�����ж��Ƿ�ΪIPV6�����򷵻�1��Neither����2��
// 3. ����������������ַ�������retStr�ж�Ӧ�Ľ����

/*
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
*/

char retStr[3][8] = {"IPv4", "IPv6", "Neither"};

// ���ж��Ƿ�ΪNeither���Ƿ����ΪIPV4��IPV6
int judge_IP(char *IP)
{
    int len;
    int dot_num = 0, colon_num = 0;
    len = strlen(IP);

    for (int i = 0; i < len; i++)
    {
        if (IP[i] == '.')
        {
            dot_num++;
        }
        else if(IP[i] == ':')
        {
            colon_num++;
        }
    }

    // ����ΪIPV4��IPV6
    if (dot_num == 3 && colon_num == 0)
        return 0;
    else if (dot_num == 0 && colon_num == 7)
        return 1;
    // Neither
    else
        return 2;
}

// �ж��Ƿ�ΪIPv4
int judge_IPv4(char *IP)
{
    int num_len[4] = {0, 0, 0, 0};
    int pos = 0;
    int i, j;
    int left = 0, right = 0, tot_num = 0;       // ÿһ��ʮ������������λ�ã����ܵ�������
    int value = 0;                              // ÿһ��ʮ�������ľ����С
    char *a, single[2] = "0";
    a = IP;

    // ��¼ÿһ��ʮ�������ֵĳ���
    while (*a != '\0')
    {
        if (*a == '.')
        {
            pos++;
            a++;
            continue;
        }  
        num_len[pos]++;
        a++;
    }

    for (i = 0; i < 4; i++)
    {
        // ����3λ�����0λ����Neither
        if (num_len[i] == 0 || num_len[i] > 3)
        {
            return 2;
        }

        // ���ÿһ��ʮ���������鿴�Ƿ�����IPv4����
        tot_num += num_len[i];
        right = tot_num + i;
        left = right - num_len[i];
        

        // ��ͷΪ0�����ֳ��ȴ���1����Ϊleading zero
        if ((right - left) > 1 && IP[left] == '0')
        {
            return 2;
        }

        // value����
        value = 0;
        for (j = left; j < right; j++)
        {
            // �ַ�����0~9
            if (IP[j] < '0' || IP[j] > '9')
            {
                return 2;
            }
            single[0] = IP[j];
            /*  for test:
            printf("char:%s\n", single);
            printf("int:%d\n", atoi(single));
            */
            value = 10 * value + atoi(single);
            /*printf("%d\n", value);*/
        }
        // ֵ����255
        if (value > 255)
        {
            return 2;
        }
    }

    // ����ʮ����������������������0
    return 0;
}

// �ж��Ƿ�ΪIPv6
int judge_IPv6(char *IP)
{
    int num_len[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int pos = 0;
    int i, j;
    int left = 0, right = 0, tot_num = 0;       // ÿһ��ʮ��������������λ�ã����ܵ�������
    char *a;
    a = IP;

    // ��¼ÿһ��ʮ���������ֵĳ���
    while (*a != '\0')
    {
        if (*a == ':')
        {
            pos++;
            a++;
            continue;
        }  
        num_len[pos]++;
        a++;
    }

    for (i = 0; i < 8; i++)
    {
        // ����4λ�����0λ����Neither
        if (num_len[i] == 0 || num_len[i] > 4)
        {
            return 2;
        }

        // ���ÿһ��ʮ�����������鿴�Ƿ�����IPv6����
        tot_num += num_len[i];
        right = tot_num + i;
        left = right - num_len[i];

        for (j = left; j < right; j++)
        {
            // �ַ�����0~9��A~F��a~f
            if ((IP[j] < '0' || IP[j] > '9') && (IP[j] < 'A' || IP[j] > 'F') && (IP[j] < 'a' || IP[j] > 'f'))
            {
                return 2;
            }
        }
    }

    // ����ʮ������������������������0
    return 1;
}

char * validIPAddress(char * IP)
{
    int type;
    type = judge_IP(IP);
    if (type == 0)
        type = judge_IPv4(IP);
    else if (type == 1)
        type = judge_IPv6(IP);

    return retStr[type];
}

/*
int main()
{
    char *IP = "192.0.0.1";
    char *type;
    type = validIPAddress(IP);
    printf("%s\n", type);

    return 0;
}
*/