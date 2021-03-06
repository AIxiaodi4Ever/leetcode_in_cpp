// leetcode:392
/*
Given a string s and a string t, check if s is subsequence of t.
A subsequence of a string is a new string which is formed from the 
original string by deleting some (can be none) of the characters without 
disturbing the relative positions of the remaining characters. 
(ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, 
and you want to check one by one to see if T has its subsequence. In this scenario, 
how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:
    0 <= s.length <= 100
    0 <= t.length <= 10^4
    Both strings consists only of lowercase characters.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/is-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// �ⷨһ����򵥵���̰��˫ָ��
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int slen = s.size(), tlen = t.size();
        int i = 0, j = 0;
        while (i < slen && j < tlen)
        {
            // �����Ӧ�ַ����s��ָ������
            if (s[i] == t[j])
                ++i;
            // �����Ƿ���ȣ�t��ָ�붼Ҫ����
            ++j;
        }
        // ���n��ָ��ûָ��β��˵������������
        return i == slen;
    }
};

// �ⷨ2����̬�滮
// ��ҪΪ�˽��������ս���൱��ʹ�ö�̬�滮������hash
// ������f[i][j]��ʾ��λ��i��ʼ���ַ�j������ֵ�λ�ã����j����i����f[i][j] = i��
// ����f[i][j] = f[i + 1][j];
// ���string t�ĳ���Ϊm����߽�Ϊm-1����f[m][...] = m��Ȼ���m-1��ʼ����dp��
// �������ĳ��f[i][j] = m��˵��i֮��û��j�ַ���
// �õ���f[i][j]֮��Ϳ��Դ�f[0]��ʼ����s��ÿһ���ַ����в�ѯ��֪��s������f[i][j] == m;
// ����dp��ʱ�䣬��ÿ���жϽ���ҪO(n)��ʱ�䣬������˫ָ���O(m+n);
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int slen = s.size(), tlen = t.size();
        // ����+1
        vector<vector<int>> firstAppear(tlen + 1, vector<int>(26, 0));
        for (int &pos : firstAppear[tlen])
            pos = tlen;

        for (int i = tlen - 1; i >= 0; --i)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (t[i] - 'a' == j)
                    firstAppear[i][j] = i;
                else
                    firstAppear[i][j] = firstAppear[i + 1][j];
            }
        }

        int i = 0, j = 0;
        while (j != slen)
        {
            int pos = firstAppear[i][s[j] - 'a'];
            if (pos == tlen)
                return false;
            // ���������false��˵��pos�ϵ��ַ��Ѿ���ȡ���ˣ�����Ӧ�ô�pos����һ��λ���ж�
            i = pos + 1;   
            ++j;
        }
        return true;
    }
};