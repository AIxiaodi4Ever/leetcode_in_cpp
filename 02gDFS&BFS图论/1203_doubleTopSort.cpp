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
        // 如果不存在拓扑排序那么res的大小一定小于items的大小，此时返回空vector
        return res.size() == items.size() ? res : vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) 
    {
        // 记录每组包含的所有Item，对于不属于任何组的Item索引从m开始
        vector<vector<int>> groupItem(m + n);

        // 组间和组内依赖图
        vector<vector<int>> groupGraph(n + m);
        vector<vector<int>> itemGraph(n);

        // 各组和各项目的入度
        vector<int> groupDeg(n + m, 0);
        vector<int> itemDeg(n, 0);

        // 记录每个小组的编号
        vector<int> id(n + m);
        for (int i = 0; i < n + m; ++i)
            id[i] = i;
        
        // 给未分配小组的Item编号，同时记录每个小组包含的所有项目
        int leftId = m;
        for (int i = 0; i < n; ++i)
        {
            if (group[i] == -1)
                group[i] = leftId++;
            groupItem[group[i]].emplace_back(i);
        }

        // 计算组内或组间的入度，同时建立依赖图
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

        // 组间拓扑排序
        vector<int> groupTopSort = topSort(groupDeg, groupGraph, id);
        if (groupTopSort.size() == 0)
            return vector<int>{};

        // 组内拓扑排序
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