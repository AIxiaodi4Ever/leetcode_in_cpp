// dp λ����
class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> bits(num + 1);
        int highBit = 0;
        for (int i = 1; i <= num; ++i)
        {
            // λ�������ȼ������߼����㣬���������
            if ((i & (i - 1)) == 0)
            {
                highBit = i;
            }
            // ���i��Ŀǰ���Ķ����ݣ���ôi-highBit=0����bits[0]=0
            bits[i] = bits[i - highBit] + 1;
        }
        return bits;
    }
};