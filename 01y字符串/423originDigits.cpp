// leetcode:423
/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, 
output the digits in ascending order.

Note:
    Input contains only lowercase English letters.
    Input is guaranteed to be valid and can be transformed to its original digits. 
That means invalid inputs such as "abc" or "zerone" are not permitted.
    Input length is less than 50,000.

Example 1:
Input: "owoztneoer"
Output: "012"

Example 2:
Input: "fviefuro"
Output: "45"

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reconstruct-original-digits-from-english
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// zero one two three four five six seven eight nine

// ����˼·�����²���Сѧ�����⡣��
// ������⣬�о�����Ҫ�����Խ�ġ���
// 1.����ż��������һ��������ַ���
// 0(zero):z  2(two):w  4(four):u  6(six):x  8(eight):g
// ֮���Ǽ���3��5��7
// h:ֻ��3(three)��8(eight)�г���; f:ֻ��5(five)��4(four)�г���; s:ֻ��6(six)��7(seven)�г���;
// ������ֻ��Ҫ����9��1
// i:ֻ��9(nine)��5(five)��6(six)��8(eight)�г��֣� n:ֻ��1(one)��7(seven)��9(nine)�г��֡�
// (���Ա����ȴ���9�ٴ���1)����Ҫע��n��9(nine)�г�����2�Ρ�
class Solution {
public:
    string originalDigits(string s) 
    {
        vector<int> letter(26 + 'a', 0);
        for (char ch : s)
        {
            letter[ch]++;
        }

        vector<int> nums(10, 0);
        // �ȴ���ż��
        nums[0] = letter['z'];
        nums[2] = letter['w'];
        nums[4] = letter['u'];
        nums[6] = letter['x'];
        nums[8] = letter['g'];
        // ֮����3��5��7
        nums[3] = letter['h'] - nums[8];
        nums[5] = letter['f'] - nums[4];
        nums[7] = letter['s'] - nums[6];
        // ����9
        nums[9] = letter['i'] - nums[5] - nums[6] - nums[8];
        // ����1
        nums[1] = letter['n'] - nums[7] - 2 * nums[9];

        string ret;
        ostringstream os;
        for (int i = 0; i < 10; ++i)
        {
            while (nums[i] > 0)
            {
                os << i;
                --nums[i];
            }
        }
        ret = os.str();
        return ret;
    }
};