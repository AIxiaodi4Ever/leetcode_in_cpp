/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/add-strings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        // ����Ӧ��ʱsize() - 1
        int i = num1.size() - 1, j = num2.size() - 1;
        int add = 0;
        string ans = "";
        while ( i >= 0 || j >= 0 || add != 0)
        {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            // ������%����&
            ans.push_back('0' + result % 10);
            add = result / 10; 
            // �ǵ�--i,--j
            --i; --j;
        }
        // reverse���ǳ�Ա����
        reverse(ans.begin(), ans.end());
        return ans;
    }
};