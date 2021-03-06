class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> C(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i)
        {
            C[0] = C[i] = 1;
            // ��Ҫ���ű�������Ϊÿ��λ�õ����յ���һ�α���ʱ��λ�ü���λ��֮ǰ����Ӱ�죬
            // ���ű������޸ĵ�ǰλ�õ��������¸�λ�õ���һ���������
            for (int j = i - 1; j > 0; --j)
            {
                C[j] = C[j - 1] + C[j];
            }
        }
        return C; 
    }
};