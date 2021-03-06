// leetcode:343
/*
Given a positive integer n, break it into the sum of at least two positive integers 
and maximize the product of those integers. Return the maximum product you can get.

Example 1:
Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 �� 1 = 1.

Example 2:
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 �� 3 �� 4 = 36.

Note: You may assume that n is not less than 2 and not larger than 58.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/integer-break
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int integerBreak(int n) 
    {
        if (n < 4)
            return n - 1;
        else
        {
            // quotient:��,��tm�л�ͷ�ʵ���˼��
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