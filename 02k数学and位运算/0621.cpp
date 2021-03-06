class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char, int> ferq;
        // 记录每个任务的执行次数
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
            // 寻找下一个最近的可执行任务的时间
            for (int j = 0; j < m; ++j)
            {
                if (rest[j])
                    minNextValid = min(nextValid[j], minNextValid);
            }
            time = max(time, minNextValid);
            // 寻找在当前时间可执行的任务种剩余次数最多的任务索引
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