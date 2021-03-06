class Solution {
public:
    string getPermutation(int n, int k) 
    {
        vector<int> factorial(n);
        factorial[0] = 1;
        // ����Ӧ�ô�1��ʼ�����ִ�д�ɴ�0��ʼ�ˡ���
        for (int i = 1; i < n; ++i)
        {
            // * ��д��� +
            factorial[i] = i * factorial[i - 1];
        }

        string ans;
        --k;
        vector<int> valid(n + 1, 1);
        for (int i = 1; i <= n; ++i)
        {
            // �����������ȡ��������Ҫfloor
            int order = k / factorial[n - i] + 1;
            for (int j = 1; j <= n; ++j)
            {
                order -= valid[j];
                if (!order)
                {
                    ans += (j + '0');
                    valid[j] = 0;
                    // ����break����
                    break;
                }
                // ���Ǹ���k
                k = k % factorial[n - i];
            }
        }
        return ans;
    }
};