class Solution {
public:
    // 分别存储答案，每次递归后节点到它所有子孙的距离和，以该节点为根的子树的节点数
    vector<int> ans, dp, sz;
    // 以邻接表的方式存图
    vector<vector<int>> graph;

    // 第一次递归求最初的dp
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

    // 第二次递归利用最初的dp求答案
    void dfs2(int u, int f)
    {
        ans[u] = dp[u];
        for (int &v : graph[u])
        {
            if (v == f)
                continue;
            /* 换根 */
            int pdu = dp[u], pdv = dp[v];
            int psu = sz[u], psv = sz[v];
            // 更新u
            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            // 更新v
            dp[v] += dp[u] + sz[u];
            //sz[v] += sz[u];
            sz[v] = psu;

            dfs2(v, u);

            // 回溯
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