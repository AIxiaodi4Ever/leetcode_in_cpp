class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool colFlag = false;
        for (int i = m - 1; i >= 0; --i) {
            if (matrix[i][0] == 0)
                colFlag = true;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[m - 1][j] = 0;    // mark last row
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[m - 1][j] == 0) {
                    matrix[i][j] = 0;
                }
            }

            if (colFlag) {
                matrix[i][0] = 0;
            }
        }
    }
};