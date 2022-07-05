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

        // 使用类二分查找，数组中存储所有小于x的2^i*y
        vector<int> candidates = {divisor};
        // 减法检测是否溢出
        while (candidates.back() >= dividend - candidates.back()) {
            candidates.push_back(candidates.back() + candidates.back());
        }
        // 逆序遍历数组，寻找答案
        int ans = 0;
        for (int i = candidates.size() - 1; i >= 0; --i) {
            if (candidates[i] >= dividend) {
                // 2^i = 1 << i
                ans += (1 << i);
                dividend -= candidates[i];
            }
        }
        return rev ? -ans : ans;
    }
};