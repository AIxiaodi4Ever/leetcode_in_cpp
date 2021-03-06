class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        // Actually m == n
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> temp(m, vector<int>(n, 0));


        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                temp[j][m - i - 1] = matrix[i][j];
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                matrix[i][j] = temp[i][j];
        }
    }
};