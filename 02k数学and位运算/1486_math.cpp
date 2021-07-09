class Solution {
public:
    int sumXor(int n) {
        int remain = n % 4;
        switch (remain) {
            case 0:
                return n;
            case 1: 
                return 1;
            case 2:
                return n + 1;
            default:
                return 0;
        }
    }

    int xorOperation(int n, int start) {
        int s = start >> 1, e = n & start & 1;
        int ans = sumXor(s - 1) ^ sumXor(s + n - 1);
        return ans << 1 | e;
    }
};