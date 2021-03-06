/*
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings 
even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

 

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
    The input string length won't exceed 1000.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/palindromic-substrings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int countSubstrings(string s) 
    {
        int len = s.size();
        int index = 0;
        string manacherized = "";
        for (int i = 0; i < 2 * len + 1; ++i)
        {
            if (i & 1)
                manacherized += s[index++];
            else
                manacherized += "#";
        }

        int len2 = manacherized.size();
        int ret = 0;
        int rbound = -1;
        int center = -1;
        vector<int> parr(len2);
        for (int i = 0; i < len2; ++i)
        {
            parr[i] = rbound > i ? min(rbound - i, parr[2 * center - i]) : 1;
            while (i + parr[i] < len2 && i - parr[i] > -1)
            {
                // ע�������Ⱦ�++parr[i],�������parr[i]�� i+parr[i] != i -parr[i]
                // Ҳ�������ϼ���Խ�磬�������ĺô��ǣ�rbound - i�����Ƕ�Ӧ�Ļ��İ뾶(ֻ��һ���ַ��ǻ��İ뾶��1)��������+1.
                // ���İ뾶�Ķ����ǰ�����ǰ�ڵ������ұ߽�ǰһ���ַ����ַ������������ö�Ӧ��c++������ҿ�����
                if (manacherized[i + parr[i]] == manacherized[i - parr[i]])
                    ++parr[i];
                else
                    break;
            }
            if (i + parr[i] > rbound)
            {
                rbound = i + parr[i];
                center = i;
            }
            ret = ret + parr[i] / 2;
        }
        return ret;
    }
};