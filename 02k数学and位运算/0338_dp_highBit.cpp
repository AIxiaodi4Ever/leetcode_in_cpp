// dp 位运算
class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> bits(num + 1);
        int highBit = 0;
        for (int i = 1; i <= num; ++i)
        {
            // 位运算优先级低于逻辑运算，必须加括号
            if ((i & (i - 1)) == 0)
            {
                highBit = i;
            }
            // 如果i是目前最大的二的幂，那么i-highBit=0，而bits[0]=0
            bits[i] = bits[i - highBit] + 1;
        }
        return bits;
    }
};