class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int total = n * n;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int top = 0, right = n - 1, bottom = n - 1, left = 0;
        int curNum = 1;
        while (left <= right && top <= bottom)
        {
            for (int c = left; c <= right; ++c) {
                ans[top][c] = curNum++;
            }
            for (int r = top + 1; r <= bottom; ++r) {
                ans[r][right] = curNum++;
            }
            if (left < right && top < bottom) {
                for (int c = right - 1; c > left; --c) {
                    ans[bottom][c] = curNum++;
                }
                for (int r = bottom; r > top; --r) {
                    ans[r][left] = curNum++;
                }
            }
            ++top;
            --right;
            --bottom;
            ++left;
        }
        return ans; 
    }
};