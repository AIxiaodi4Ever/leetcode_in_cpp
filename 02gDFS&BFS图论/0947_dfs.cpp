class Solution {
public:
    void dfs(int x, vector<vector<int>>& edges, vector<bool>& vis)
    {
        vis[x] = true;
        for (int& y : edges[x])
        {
            if (!vis[y])
                dfs(y, edges, vis);
        }
    }

    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();
        vector<bool> vis(n, false);
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        int remain = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                ++remain;
                dfs(i, edges, vis);
            }
        }

        return n - remain;
    }
};