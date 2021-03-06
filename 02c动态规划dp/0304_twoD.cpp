class NumMatrix {
public:
    vector<vector<int>> preSumTwoD;

    NumMatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        if (m > 0)
        {
            // 大小为m+1 x n+1是为了方便row1, col1 == 0的情况
            int n = matrix[0].size();
            preSumTwoD.resize(m + 1, vector<int>(n + 1));
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    preSumTwoD[i + 1][j + 1] = preSumTwoD[i][j + 1] + preSumTwoD[i + 1][j] + matrix[i][j] - preSumTwoD[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return preSumTwoD[row2 + 1][col2 + 1] - preSumTwoD[row2 + 1][col1] - preSumTwoD[row1][col2 + 1] + preSumTwoD[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */