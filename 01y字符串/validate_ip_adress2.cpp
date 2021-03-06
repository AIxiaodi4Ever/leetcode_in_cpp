#include <string.h>
#include <stdlib.h>
#include <memory.h>


#define MIN_IPV4_LEN 7
#define MAX_IPV4_LEN 15
#define MIN_IPV6_LEN 15
#define MAX_IPV6_LEN 39

#define NEITHER_STR "Neither"
#define IPV4_STR "IPv4"
#define IPV6_STR "IPv6"
#define MAX_NUM_LEN 5

char g_strIPStr[MAX_NUM_LEN];
int g_len;

bool isExpectIPv4Num(int numCnt)
{
    int i = 0;
    int num = 0;
    int strLen = strlen(g_strIPStr);
    if (strLen == 0) {
        return false;
    }
    while (g_strIPStr[i] != '\0') {
        // ������0��ͷ
        if (i != 0 && num == 0 && g_strIPStr[i] != '0') {
            return false;
        }
        num = num + (g_strIPStr[i] - '0') * pow(10, strLen - 1 - i);
        i++;
    }
    // ����������0
    if ((strLen > 1 && num == 0)) {
        return false;
    }
    // ����Ч����
    if (num >= 0 && num <= 255) {
        return true;
    }
    return false;
}

bool isExpectIPv6Num()
{
    int i = 0;
    int strLen = strlen(g_strIPStr);
    if (strLen == 0) {
        return false;
    }
    while (g_strIPStr[i] != '\0') {
        if (((g_strIPStr[i] >= '0' && g_strIPStr[i] <= '9') || 
            (g_strIPStr[i] >= 'a' && g_strIPStr[i] <= 'f') ||
            (g_strIPStr[i] >= 'A' && g_strIPStr[i] <= 'F')) == false) {
                return false;
        }
        i++;
    }

    return true;
}

bool isIPV4Address(char* IP, int strLen)
{
    // �߽�����
    int dotNum = 0;
    int itemNum = 0;
    int curPos = 0;
    g_len = 0;
    if (IP[0] == '.') {
        return false;
    }
    memset(g_strIPStr, 0, MAX_NUM_LEN);
    // ����
    while(curPos < (strLen + 1)) {
        if (IP[curPos] == '.' || IP[curPos] == '\0') {
            // 
            g_strIPStr[g_len] = '\0';
            if(isExpectIPv4Num(itemNum) == false) {
                return false;
            }
            // 
            if (IP[curPos] == '.') {
                dotNum++;
                curPos++;
                g_len = 0;
            }
            itemNum++;
            
            if (IP[curPos] == '\0') {
                if (dotNum == 3 && itemNum == 4) {
                    return true;
                }
                return false;
            }
        } else if (g_len < 3) {
            g_strIPStr[g_len++] = IP[curPos];
            curPos++;
        } else {
            return false;
        }
        
    } 
    return false;
}

bool isIPV6Address(char* IP, int strLen)
{
    // �߽�����
    int dotNum = 0;
    int itemNum = 0;
    int curPos = 0;
    g_len = 0;
    if (IP[0] == ':') {
        return false;
    }
    memset(g_strIPStr, 0, MAX_NUM_LEN);
    // ����
    while(curPos < (strLen + 1)) {
        if (IP[curPos] == ':' || IP[curPos] == '\0') {
            // 
            g_strIPStr[g_len] = '\0';
            if(isExpectIPv6Num() == false) {
                return false;
            }
            // 
            if (IP[curPos] == ':') {
                dotNum++;
                curPos++;
                g_len = 0;
            }
            itemNum++;
            
            if (IP[curPos] == '\0') {
                if (dotNum == 7 && itemNum == 8) {
                    return true;
                }
                return false;
            }
        } else if (g_len < 4) {
            g_strIPStr[g_len++] = IP[curPos];
            curPos++;
        } else {
            return false;
        }
        
    } 
    return false;
}

char* validIPAddress(char* IP){
    int strLen = strlen(IP);
    bool bRet = false;
    int start = 0;
    int dotCnt = 0;
    int numCnt = 0;
    // �ǲ���ipv4
    if ((strLen >= MIN_IPV4_LEN && strLen <= MAX_IPV4_LEN) && (bRet = isIPV4Address(IP, strLen)) == true) {
        return IPV4_STR;
    }
    if ((strLen >= MIN_IPV6_LEN && strLen <= MAX_IPV6_LEN) && (bRet = isIPV6Address(IP, strLen)) == true) {
        // �ǲ���ipv6
        return IPV6_STR;
    }
    
    // �Ȳ���ipv4 Ҳ����ipv6
    return NEITHER_STR;
}

/*
���ߣ�mu-meng-wei-yu
���ӣ�https://leetcode-cn.com/problems/validate-ip-address/solution/cyu-yan-0ms-by-mu-meng-wei-yu-2/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/