/*Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/multiply-strings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/

class Solution {
public:
    string addString(string &s1, string &s2)
    {
        int i = s1.size() - 1, j = s2.size() - 1;
        string ret = "";
        int add = 0;
        // �������⽫s1��s2��ת
        while (i >= 0 || j >= 0 || add != 0)
        {
            // 3.����j���±�����Ӧ��ȡj������TMȡ��i
            int x = i >= 0 ? s1[i] - '0' : 0;
            int y = j >= 0 ? s2[j] - '0' : 0;
            int result = x + y + add;
            add = result / 10;
            ret.push_back(result % 10 + '0'); 
            // 2.���������˽�i,j--����
            --i;
            --j;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string multiply(string num1, string num2) 
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.size(), len2 = num2.size();
        // ans��ʼΪ0Ϊ��֮�����ӷ�
        string ans = "0";
        for (int i = len1 - 1; i >= 0; --i)
        {
            string curr = "";
            for (int j = len1 - 1; j > i; --j)
                curr.push_back('0');
            int add = 0;
            int fac1 = num1[i] - '0';
            // 1.������--д�����++
            for (int j = len2 - 1; j >= 0; --j)
            {
                int fac2 = num2[j] - '0';
                int result = fac1 * fac2 + add;
                curr.push_back(result % 10 + '0');
                add = result / 10;
            }
            // ��λ���ܴ���9    
            while (add != 0)
            {
                curr.push_back(add % 10 + '0');
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            ans = addString(ans, curr);            
        }
        return ans;
    }
};