class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char, int> ferq;
        // ��¼ÿ�������ִ�д���
        for (const char &c : tasks)
            ++ferq[c];
        int m = ferq.size();
        vector<int> nextValid, rest;
        for (const auto& [_, v] : ferq)
        {
            nextValid.push_back(1);
            rest.push_back(v);
        }
        int time = 0;
        for (int i = 0; i < tasks.size(); ++i)
        {
            ++time;
            int minNextValid = INT_MAX;
            // Ѱ����һ������Ŀ�ִ�������ʱ��
            for (int j = 0; j < m; ++j)
            {
                if (rest[j])
                    minNextValid = min(nextValid[j], minNextValid);
            }
            time = max(time, minNextValid);
            // Ѱ���ڵ�ǰʱ���ִ�е�������ʣ�����������������
            int best = -1;
            for (int j = 0; j < m; ++j)
            {
                if (rest[j] && nextValid[j] <= time)
                {
                    if (best == -1 || rest[j] > rest[best])
                        best = j;
                }
            }
            nextValid[best] = time + n + 1;
            --rest[best];
        }
        return time;
    }
};