class Solution {
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    // û��������������Ϊ�㷨�е����ѡ���������ֽ��������Ѿ���������������������
    // �ӷ��ͳ˷���ǰ������Ϊ���㽻���ɱ����Ż�
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVEDE = 3;

    bool judgePoint24(vector<int>& nums) 
    {
        vector<double> dnums;
        for (const int& num : nums)
        {
            dnums.emplace_back(static_cast<double>(num));
        }
        return solve(dnums);
    }

    bool solve(vector<double> &dnums)
    {
        // ����������������ᷢ������������������if���
        /*if (dnums.size() == 0)
            return false;*/
        
        // ��ֻʣ��һ���������ж��Ƿ�Ϊ24
        if (dnums.size() == 1)
            return fabs(dnums[0] - TARGET) < EPSILON;

        int size = dnums.size();
        // ����0��ʼ����Ϊ10��01��һ��
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                // ��ͬ����֮���޷�����
                if (i != j)
                {
                    vector<double> dnums2{};
                    for (int k = 0; k < size; ++k)
                    {
                        if (k != i && k != j)
                            dnums2.emplace_back(dnums[k]);
                    }

                    // ������k < 4������k < size������
                    for (int k = 0; k < 4; ++k)
                    {
                        // �Խ����ɵ��Ż�
                        if ( k < 2 && i < j )
                            continue;

                        // һ��ֻ�ܽ���һ������������if else if����ʽ
                        if (k == ADD)
                            dnums2.emplace_back(dnums[i] + dnums[j]);                 
                        else if (k == MULTIPLY)
                            dnums2.emplace_back(dnums[i] * dnums[j]);
                        else if (k == SUBTRACT)
                            dnums2.emplace_back(dnums[i] - dnums[j]);
                        else if (k == DIVEDE)
                        {
                            // ��ֹ����0������ҲҪ�þ���ֵ
                            if (fabs(dnums[j]) < EPSILON)
                                continue;
                            dnums2.emplace_back(dnums[i] / dnums[j]);
                        }

                        // ���ж��Ƿ�Ϊ�棬�پ����Ƿ񷵻�
                        // Ϊ�����Ϣ��˻�һֱ���ص���һ��ݹ�
                        // ��Ϊ�ٵ���Ϣֻ�������һ��������ļ���򷵻ص���һ��
                        if (solve(dnums2))
                            return true;
                        dnums2.pop_back();
                    }
                }
            }
        }
        return false;
    }
};
