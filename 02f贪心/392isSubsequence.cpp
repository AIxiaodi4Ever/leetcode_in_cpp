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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解法一：简简单单的贪心双指针
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int slen = s.size(), tlen = t.size();
        int i = 0, j = 0;
        while (i < slen && j < tlen)
        {
            // 如果对应字符相等s的指针自增
            if (s[i] == t[j])
                ++i;
            // 无论是否相等，t的指针都要自增
            ++j;
        }
        // 如果n的指针没指向尾后，说明不是子序列
        return i == slen;
    }
};

// 解法2：动态规划
// 主要为了解决后续挑战，相当于使用动态规划计算了hash
// 首先用f[i][j]表示从位置i开始，字符j最早出现的位置，如果j就在i，则f[i][j] = i，
// 否则f[i][j] = f[i + 1][j];
// 如果string t的长度为m，则边界为m-1，令f[m][...] = m，然后从m-1开始倒着dp；
// 这样如果某个f[i][j] = m，说明i之后没有j字符。
// 得到了f[i][j]之后就可以从f[0]开始，对s的每一个字符进行查询，知道s结束或f[i][j] == m;
// 不算dp的时间，则每次判断仅需要O(n)的时间，而不是双指针的O(m+n);
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int slen = s.size(), tlen = t.size();
        // 行数+1
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
            // 如果不返回false，说明pos上的字符已经读取过了，所以应该从pos的下一个位置判断
            i = pos + 1;   
            ++j;
        }
        return true;
    }
};