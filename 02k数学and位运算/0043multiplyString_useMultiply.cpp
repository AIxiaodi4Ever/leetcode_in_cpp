class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        const int m = num1.size(), n = num2.size();
        vector<int> vans(m + n);
        for (int i = m - 1; i >= 0; --i)
        {
            int x = num1[i] - '0';
            // 1.>=0��д��>0
            for (int j = n - 1; j >= 0; --j)
            {
                int y = num2[j] - '0';
                vans[i + j + 1] += x * y;
            }
        }
        int add = 0;
        // �������������⣬���ü��
        for (int i = m + n - 1; i > 0; --i)
        {
            vans[i - 1] += vans[i] / 10;
            vans[i] %= 10;
        }
        // �������Ҳ������⣬��ԭ��ǰ��0������ȥ���ġ���
        int index = vans[0] == 0 ? 1 : 0;
        string ans = "";
        while (index < m + n)
        {
            ans.push_back(vans[index] + '0');
            // 2.���ǵ���index
            ++index;
        }
        return ans;
    }
};