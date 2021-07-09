class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // f[i - 2], f[i - 1], f[i], i means ith char in s.
        int a = 0, b = 1, c;
        for (int i = 1; i <= n; ++i) {
            c = 0;
            if (s[i - 1] != '0') {
                c += b;
            }
            if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26) {
                c += a;
            }
            tie(a, b) = {b, c};
        }
        return c;
    }
};