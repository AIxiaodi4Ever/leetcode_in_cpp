class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        // 1.��һ����ǰ����i��λ�ã�����i-1�������ֻ������Կ�����i/2����
        // 2.������֮����j-i-1��λ�ã�����j-i-3�������ֻ������Կ�����(j-i-2)/2����
        // 3.���һ����������m-k-1��λ�ã�����m-k-2�������ֻ������Կ�����(m-k-1)/2����
        // 4.���������԰�ǿյģ��Ǿ���m��λ�����ֻ������Կ�����(m+1)/2����
        int m = flowerbed.size();   // �ض���n���³���
        int prev = -1, count = 0;
        for (int i = 0; i < m; ++i)
        {
            if (flowerbed[i] == 1)
            {
                if (prev == -1)
                    count += i / 2;
                else
                    count += (i - prev - 2) / 2;
            
                if (count >= n)
                    return true;
                // ����仰д����if���浼�³���
                prev = i;
            }
        }
        if (prev == -1)
            count += (m + 1) / 2;
        else
            count += (m - prev - 1) / 2;

        return count >= n;
    }
};