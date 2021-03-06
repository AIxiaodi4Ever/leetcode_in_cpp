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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-rotation-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
 旋转的意思是以某个索引为中心，而不是直接reverse
 因此方法是将s2或s1与自身相加，这样另一个一定会出现在结果中，
 如果不出现则说明false
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