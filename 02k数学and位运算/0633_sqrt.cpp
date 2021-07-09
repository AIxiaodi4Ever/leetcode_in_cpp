class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a * a <= c; ++a) {
            double b = sqrt(c - a * a);
            if (b == (int)b) {
                return true;
            }
        }
        return false;
    }
};