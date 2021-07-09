class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int b = 2; b * b < c; ++b) {
            // 不是因子，枚举下一个
            if (c % b != 0) {
                continue;
            }

            int exp = 0;
            while (c % b == 0) {
                c /= b;
                ++exp;
            }

            if (b % 4 == 3 && exp % 2 != 0) {
                return false;
            }
        }
        // 自身是质数时判断(比如11)
        return c % 4 != 3;
    }
};