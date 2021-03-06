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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-original-digits-from-english
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// zero one two three four five six seven eight nine

// 解题思路：被吐槽是小学奥数题。。
// 看下题解，感觉还是要动点脑筋的。。
// 1.所有偶数都包含一个特殊的字符：
// 0(zero):z  2(two):w  4(four):u  6(six):x  8(eight):g
// 之后是计算3，5，7
// h:只在3(three)，8(eight)中出现; f:只在5(five)，4(four)中出现; s:只在6(six)，7(seven)中出现;
// 接下来只需要处理9和1
// i:只在9(nine)，5(five)，6(six)，8(eight)中出现， n:只在1(one)，7(seven)，9(nine)中出现。
// (所以必须先处理9再处理1)，还要注意n在9(nine)中出现了2次。
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
        // 先处理偶数
        nums[0] = letter['z'];
        nums[2] = letter['w'];
        nums[4] = letter['u'];
        nums[6] = letter['x'];
        nums[8] = letter['g'];
        // 之后处理3，5，7
        nums[3] = letter['h'] - nums[8];
        nums[5] = letter['f'] - nums[4];
        nums[7] = letter['s'] - nums[6];
        // 处理9
        nums[9] = letter['i'] - nums[5] - nums[6] - nums[8];
        // 处理1
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