class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y)
        {
            // ans *=  (x / y);
            // because of float number, ans above is wrong
            // but how to ensure the ans below is integer...
            ans = ans * x / y;
        }
        return ans;
    }
};