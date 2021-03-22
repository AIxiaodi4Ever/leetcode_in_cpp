class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};

        int rows = matrix.size(), columns = matrix[0].size();
        int top = 0, right = columns - 1, bottom = rows - 1, left = 0;
        vector<int> ans;
        while (left <= right && top <= bottom) {
            for (int c = left; c <= right; ++c)
                ans.push_back(matrix[top][c]);
            for (int r = top + 1; r <= bottom; ++r)
                ans.push_back(matrix[r][right]);
            if (left < right && top < bottom) {
                for (int c = right - 1; c > left; --c)
                    ans.push_back(matrix[bottom][c]);
                for (int r = bottom; r > top; --r)
                    ans.push_back(matrix[r][left]);
            }
            ++top;
            --right;
            --bottom;
            ++left;
        }
        return ans;
    }
};