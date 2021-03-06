class Solution {
public:
    void qsort(vector<pair<int, int>>& v, int start, int end, vector<int>& ret, int k)
    {
        // picked�ķ�Χ��[0,end-start]
        int picked = rand() % (end - start + 1) + start;

        swap(v[picked], v[start]);

        int pivot = v[start].second;
        int index = start;
        for (int i = start + 1; i <= end; ++i)
        {
            if (v[i].second >= pivot)
            {
                swap(v[i], v[index + 1]);
                ++index;
            }
        }
        swap(v[index], v[start]);

        if (k <= index - start)
            // index - 1 ����index
            qsort(v, start, index - 1, ret, k);
        else
        {
            // �ӵ�ǰ��start��ʼ�������Ǵ�0��ʼ
            for (int i = start; i <= index; ++i)
                ret.push_back(v[i].first);
            if (k > index - start + 1)
                qsort(v, index + 1, end, ret, k - (index - start + 1));
        }        
    }

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> occurences;
        for (auto& v : nums)
            ++occurences[v];

        vector<pair<int, int>> values;
        for (const auto& kv : occurences)
            values.push_back(kv);
        vector<int> ret;
        qsort(values, 0, values.size() - 1, ret, k);
        return ret;
    }
};