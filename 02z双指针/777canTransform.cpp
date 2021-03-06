// leetcode:777

/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", 
a move consists of either replacing one occurrence of "XL" with "LX", 
or replacing one occurrence of "RX" with "XR". Given the starting string 
start and the ending string end, return True if and only if there exists 
a sequence of moves to transform one string to the other.

Example:
Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Constraints:
    1 <= len(start) == len(end) <= 10000.
    Both start and end will only consist of characters in {'L', 'R', 'X'}.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/swap-adjacent-in-lr-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·��ͬʱ����ת�������ԺͿɵ�����
// L��ʾ������ߵ��ˣ�R��ʾ�����ұߵ��ˣ�
// ת�������ԣ�start��end�ַ����е�L��R�����λ�ò��䣻
/************************************************************/
// �ɵ����ԣ���n��L�������ƶ�����ʼλ��֮�󣬵�n��R�������ƶ�����ʼλ��֮ǰ��
// ����start��L��λ��һ�����ڻ���end��L��λ��֮ǰ��ͬ��start�е�Rһ����end��R֮ǰ����ȡ�
// �������֤�������Ҳ�֪��

bool canTransform(char * start, char * end)
{
    int len = strlen(start);
    int i = -1, j = -1;
    // ����Ӧ���� <= �� �������
    // �����С�����һ���ж�����if�޷�ִ��
    while (++i <= len && ++j <= len)
    {
        while(i < len && start[i] == 'X')
            ++i;
        while(j < len && end[j] == 'X')
            ++j;

        // ���i��j��ֻ��һ��С��len����һ������n��
        // ��˵��start��end�е�һ������������������һ����
        if ((i < len) ^ (j < len))
            return false;
        if (i < len && j < len)
        {
            if (start[i] != end[j] || (start[i] == 'L' && i < j) ||
                (start[i] == 'R' && i > j))
                return false;
        }
    }
    return true;
}