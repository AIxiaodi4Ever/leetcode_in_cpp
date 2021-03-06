class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> temp;
        vector<vector<int>> ans;

        for (int i = 1; i <= k; ++i)
            temp.push_back(i);
        temp.push_back(n + 1);
        
        int j = 0;
        while (j < k)
        {
            ans.emplace_back(temp.begin(), temp.begin() + k);
            // Ѱ�ҵ�һ��temp[j]+1 != temp[j+1]��λ��
            // ��0~j-1λ�ô�������λ(�Ƶ����λ)
            // �ⲽ�ܹؼ���ÿ�ζ�Ҫ��j��0����ͷ��ʼ��
            j = 0;
            while (j < k && temp[j] + 1 == temp[j + 1])
            {
                temp[j] = j + 1;
                ++j;
            }
            // ��ʱj�ǵ�һ��temp[j]+1!=temp[j+1]��λ��
            ++temp[j];
        }

        return ans;
    }
};