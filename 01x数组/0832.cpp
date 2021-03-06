class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
    {
        // 和1异或就能反转，
        int n = A.size();
        for (int i = 0; i < n; ++i)
        {
            int left = 0, right = n - 1;
            while (left < right)
            {
                if (A[i][left] == A[i][right])
                {
                    A[i][left] ^= 1;
                    A[i][right] ^= 1;
                }
                ++left;
                --right;
            }
            if (left == right)
                A[i][left] ^= 1;            
        }
        return A;
    }
};