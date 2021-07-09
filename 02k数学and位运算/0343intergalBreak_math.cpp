// leetcode:343
/*
Given a positive integer n, break it into the sum of at least two positive integers 
and maximize the product of those integers. Return the maximum product you can get.

Example 1:
Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

Note: You may assume that n is not less than 2 and not larger than 58.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int integerBreak(int n) 
    {
        if (n < 4)
            return n - 1;
        else
        {
            // quotient:商,还tm有回头率的意思，
            int quotient = n / 3;
            int reminder = n % 3;
            if (reminder == 0)
                return pow(3,quotient);
            else if (reminder == 1)
                return pow(3, quotient - 1) * 4;
            else
                return pow(3, quotient) * 2;
        }
    }
};