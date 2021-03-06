/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/valid-parentheses
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    bool isValid(string s) {
        if (s.size() & 1)
            return false;
        unordered_map<char, char> pairs( {{')', '('}, {']', '['}, {'}', '{'}} );
        stack<char> bracket;
        for (auto c : s)
        {
            if (pairs.count(c))
            {
                if (bracket.empty() || bracket.top() != pairs[c])
                    return false;
                bracket.pop();
            }
            else
                bracket.push(c);
        }
        return bracket.empty();
    }
};