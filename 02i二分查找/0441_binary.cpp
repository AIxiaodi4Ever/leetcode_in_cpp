class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)mid * (mid + 1) <= (long long)2 * n) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};