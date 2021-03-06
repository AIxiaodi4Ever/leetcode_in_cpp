class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> C(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i)
        {
            C[0] = C[i] = 1;
            // 需要倒着遍历，因为每个位置的数收到上一次遍历时该位置及该位置之前的数影响，
            // 正着遍历会修改当前位置的数，导致该位置的下一个计算出错。
            for (int j = i - 1; j > 0; --j)
            {
                C[j] = C[j - 1] + C[j];
            }
        }
        return C; 
    }
};