class Solution {
public:
    // C(n, m) = C(n, m - 1) * (n - m + 1) / m;
    vector<int> getRow(int rowIndex) 
    {
        vector<int> C(rowIndex + 1);
        C[0] = 1;
        for (int i = 1; i <= rowIndex; ++i)
        {
            // 前面加上1LL提升成long long否则乘法可能整型溢出
            C[i] = 1LL * C[i - 1] * (rowIndex - i + 1) / i;
        }
        return C;
    }   
};