class Solution {
public:
    // �ֱ�洢�𰸣�ÿ�εݹ��ڵ㵽����������ľ���ͣ��Ըýڵ�Ϊ���������Ľڵ���
    vector<int> ans, dp, sz;
    // ���ڽӱ�ķ�ʽ��ͼ
    vector<vector<int>> graph;

    // ��һ�εݹ��������dp
    void dfs(int u, int f)
    {
        dp[u] = 0;
        sz[u] = 1;
        for (int &v : graph[u])
        {
            if (v == f)
                continue;
            dfs(v, u);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    }

    // �ڶ��εݹ����������dp���
    void dfs2(int u, int f)
    {
        ans[u] = dp[u];
        for (int &v : graph[u])
        {
            if (v == f)
                continue;
            /* ���� */
            int pdu = dp[u], pdv = dp[v];
            int psu = sz[u], psv = sz[v];
            // ����u
            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            // ����v
            dp[v] += dp[u] + sz[u];
            //sz[v] += sz[u];
            sz[v] = psu;

            dfs2(v, u);

            // ����
            dp[u] = pdu;
            dp[v] = pdv;
            sz[u] = psu;
            sz[v] = psv;
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) 
    {
        ans.resize(N, 0);
        dp.resize(N, 0);
        sz.resize(N, 0);
        graph.resize(N, {});
        for (vector<int> &edge : edges)
        {
            int u = edge[0], v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};