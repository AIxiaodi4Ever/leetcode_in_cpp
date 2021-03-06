class Solution {
public:
    /* ������ʱ��ָ��ֻ����ƶ�һλ����֤��������󳤶Ȳ��� */
    int equalSubstring(string s, string t, int maxCost) 
    {
        int n = s.size();
        int head = 0, tail = 0;
        int sum = 0;
        while (tail < n)
        {
            sum += abs(t[tail] - s[tail++]);
            if (sum > maxCost)
                sum -= abs(t[head] - s[head++]);
        }
        return tail - head;
    }
};