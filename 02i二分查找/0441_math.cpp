class Solution {
public:
    int arrangeCoins(int n) {
        // 设解为x，则x*(x+1) = 2*n，则 x = (-1 + sqrt(8n + 1)) / 2，向下取整即可
        return (int)((sqrt((long long)8 * n + 1) - 1) / 2);
    }
};