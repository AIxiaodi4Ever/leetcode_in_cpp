const long long mod = 1e9 + 7;

class Solution {
public:
    vector<vector<long long>> matrixMult(vector<vector<long long>>& mat1, vector<vector<long long>>& mat2) {
        int n1 = mat1.size(), n2 = mat2.size(), n3 = mat2[0].size();
        vector<vector<long long>> mat3(n1, vector<long long>(n3, 0));
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n3; ++j) {
                for (int k = 0; k < n2; ++k) {
                    mat3[i][j] = (mat3[i][j]+ mat1[i][k] * mat2[k][j]) % mod;
                }
            }
        }
        return mat3;
    }

    int numTilings(int n) {
        vector<vector<long long>> mat = {{0, 0, 0, 1},
                                         {1, 0, 1, 0},
                                         {1, 1, 0 ,0},
                                         {1, 1, 1, 1}};

        vector<vector<long long>> matn = {{1, 0, 0, 0},
                                          {0, 1, 0, 0},
                                          {0, 0, 1, 0},
                                          {0, 0, 0, 1}};
        

        // the logic below is that if num is 2^n + m, then we calculate mat^(2^n) by iteration and calculate mat^(m) in if statement. 
        while(n) {
            if (n & 1) {
                matn = matrixMult(matn, mat);
            } 
            mat = matrixMult(mat, mat);
            n >>= 1;
        }

        return matn[3][3];
    }
};