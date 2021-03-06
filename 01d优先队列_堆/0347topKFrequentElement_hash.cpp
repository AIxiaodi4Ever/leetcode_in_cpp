class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n)
    {
        // priority_queue默认使用less生成大顶堆
        // 所以这里用>号生成小顶堆
        return m.second > n.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> occurences;
        for (const int& num : nums)
            occurences[num]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& curr : occurences)
        {
            if (q.size() == k)
            {
                if (curr.second > q.top().second)
                {
                    q.pop();
                    q.emplace(curr);
                }
            }
            else
            {
                q.emplace(curr);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};