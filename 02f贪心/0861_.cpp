class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int sum = m * (1 << (n - 1));
        // j start at index 1
        for (int j = 1; j < n; ++j)
        {
            int nOnes = 0;
            for (int i = 0; i < m; ++i)
            {
                if (A[i][0] == 1)
                    nOnes += A[i][j];
                else
                    nOnes += (1 - A[i][j]); // if this line is fliped the value is actually 1 - A[i][j]
            }
            nOnes = max(nOnes, m - nOnes);
            sum += nOnes * (1 << (n - j - 1));
        }
        return sum;
    }
};