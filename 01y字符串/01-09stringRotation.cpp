/*
Given two strings, s1 and s2, write code to check if s2 is 
a rotation of s1 (e.g.,"waterbottle" is a rotation of"erbottlewat"). 
Can you use only one call to the method that checks if one word is a 
substring of another?

Example 1:
Input: s1 = "waterbottle", s2 = "erbottlewat"
Output: True

Example 2:
Input: s1 = "aa", "aba"
Output: False

Note:
    0 <= s1.length, s1.length <= 100000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/string-rotation-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*
 ��ת����˼����ĳ������Ϊ���ģ�������ֱ��reverse
 ��˷����ǽ�s2��s1��������ӣ�������һ��һ��������ڽ���У�
 �����������˵��false
*/

class Solution {
public:
    bool isFlipedString(string s1, string s2) 
    {
        if (s1.size() != s2.size())
            return false;
        string merge = s2 + s2;
        return merge.find(s1) == string::npos ? false : true;
    }
};