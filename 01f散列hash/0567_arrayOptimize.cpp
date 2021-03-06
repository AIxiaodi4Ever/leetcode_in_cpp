class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.size(), m = s2.size();
        // s1��s2����һ��������
        if (n > m)
            return false;
        vector<int> cnt(26, 0);
        // s1��--��s2��++����������������s2ʱ������Ƴ����������Ҫ������
        for (int i = 0; i < n; ++i)
        {
            --cnt[s1[i] - 'a'];
            ++cnt[s2[i] - 'a'];
        }
        int diff = 0;
        for (int c : cnt)
        {
            if (c != 0)
                ++diff;
        }
        if (diff == 0)  
            return true;

        // ����Ĵ���û���ǳ�ʼ�Ĵ��ڣ�����ǰ��Ҫ��if
        for (int i = n; i < m; ++i)
        {
            int x = s2[i - n] - 'a', y = s2[i] - 'a';
            if (x == y)
                continue;
            // �Ƴ�x
            if (cnt[x] == 0)
                ++diff;
            --cnt[x];
            if (cnt[x] == 0)
                --diff;

            // ����y
            if (cnt[y] == 0)
                ++diff;
            ++cnt[y];
            if (cnt[y] == 0)
                --diff;
            if (diff == 0)
                return true;
        }
        return false;
    }
};