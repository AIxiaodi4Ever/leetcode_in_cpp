class Solution {
public:
    int divide(int dividend, int divisor) {
        // 考虑被除数为最小值的情况
        if (dividend == INT_MIN) {
            if (divisor == 1) {
                return INT_MIN;
            }
            if (divisor == -1) {
                return INT_MAX;
            }
        }
        // 考虑除数为最小值的情况
        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }
        // 考虑被除数为0
        if (dividend == 0) {
            return 0;
        }

        // 将被除数及除数均变为负数，同时记录答案是否变号
        bool rev = false;
        if (dividend > 0) {
            dividend = -dividend;
            rev = !rev;
        }
        if (divisor > 0) {
            divisor = -divisor;
            rev = !rev;
        }

        /* 快速乘/幂的原理就是把乘数z(或幂z)写成2的幂的形式，例如：
        15 * y = y + 2y + 4y + 8y */
        // lambda定义快速乘，xy小于0，z大于0，判断 z*y >= x
        auto quickMul = [](int y, int z, int x)->bool {
            int result = 0, add = y; // 我tm一开始把这个写进while里面去了
            while (z) {
                // 为了防止溢出，加法的检测改成减法
                if (z & 1) {
                    if (result < x - add) {
                        return false;
                    }
                    result += add;
                }
                if (z != 1) {
                    if (add < x - add) {
                        return false;
                    }
                    add += add;
                }
                // 不能用除法
                z >>= 1;
            }
            return true;
        };

        // 二分搜索
        int left = 1, right = INT_MAX, ans = 0;
        while (left <= right) {
            // 防止溢出，同时不能用除法，且移位运算的优先级低于算数运算
            int mid = left + ((right - left) >> 1);
            bool check = quickMul(divisor, mid, dividend);
            if (check) {
                ans = mid;
                if (mid == INT_MAX) {
                    break;
                }
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return rev ? -ans : ans;
    }
};