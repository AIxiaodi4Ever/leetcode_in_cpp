class Solution {
public:
    vector<int> topSort(vector<int>& deg, vector<vector<int>>& graph, vector<int>& items)
    {
        queue<int> Q;
        for (auto& item : items)
        {
            if (deg[item] == 0)
                Q.push(item);
        }

        vector<int> res;
        while (!Q.empty())
        {
            int u= Q.front();
            Q.pop();
            res.emplace_back(u);
            for (auto& v : graph[u])
            {
                if (--deg[v] == 0)
                    Q.push(v);
            }
        }
        // �������������������ôres�Ĵ�Сһ��С��items�Ĵ�С����ʱ���ؿ�vector
        return res.size() == items.size() ? res : vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) 
    {
        // ��¼ÿ�����������Item�����ڲ������κ����Item������m��ʼ
        vector<vector<int>> groupItem(m + n);

        // ������������ͼ
        vector<vector<int>> groupGraph(n + m);
        vector<vector<int>> itemGraph(n);

        // ����͸���Ŀ�����
        vector<int> groupDeg(n + m, 0);
        vector<int> itemDeg(n, 0);

        // ��¼ÿ��С��ı��
        vector<int> id(n + m);
        for (int i = 0; i < n + m; ++i)
            id[i] = i;
        
        // ��δ����С���Item��ţ�ͬʱ��¼ÿ��С�������������Ŀ
        int leftId = m;
        for (int i = 0; i < n; ++i)
        {
            if (group[i] == -1)
                group[i] = leftId++;
            groupItem[group[i]].emplace_back(i);
        }

        // �������ڻ�������ȣ�ͬʱ��������ͼ
        for (int i = 0; i < n; ++i)
        {
            int curGroupId = group[i];
            for (auto& item : beforeItems[i])
            {
                int beforeGroupId = group[item];
                if (curGroupId == beforeGroupId)
                {
                    ++itemDeg[i];
                    itemGraph[item].emplace_back(i);
                }
                else
                {
                    ++groupDeg[curGroupId];
                    groupGraph[beforeGroupId].emplace_back(curGroupId);
                }
            }
        }

        // �����������
        vector<int> groupTopSort = topSort(groupDeg, groupGraph, id);
        if (groupTopSort.size() == 0)
            return vector<int>{};

        // ������������
        vector<int> ans;
        for (auto& curGroupId : groupTopSort)
        {
            if (groupItem[curGroupId].size() == 0)
                continue;
            vector<int> res = topSort(itemDeg, itemGraph, groupItem[curGroupId]);
            if (res.size() == 0)
                return vector<int>{};
            for (auto& item : res)
                ans.emplace_back(item);
        }

        return ans;
    }
};