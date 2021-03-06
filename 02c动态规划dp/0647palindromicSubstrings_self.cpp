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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
                // 注意如果相等就++parr[i],所以最够的parr[i]是 i+parr[i] != i -parr[i]
                // 也可能以上计算越界，这样做的好处是，rbound - i正好是对应的回文半径(只有一个字符是回文半径是1)，而不用+1.
                // 回文半径的定义是包括当前节点自身到右边界前一个字符中字符的总数，正好对应了c++的左闭右开区间
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