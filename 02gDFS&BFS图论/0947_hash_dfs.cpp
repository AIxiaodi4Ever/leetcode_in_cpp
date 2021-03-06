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
        vector<vector<int>> edges(n);
        unordered_map<int , vector<int>> rec;
        for (int i = 0; i < n; ++i)
        {
            // x,y范围均为[1,10^4]所有可以共用hash
            rec[stones[i][0]].push_back(i);
            rec[stones[i][1]+10000].push_back(i);
        }

        for (auto& [_, vec] : rec)
        {
            int k = vec.size();
            for (int i = 1; i < k; ++i)
            {
                edges[vec[i - 1]].push_back(vec[i]);
                edges[vec[i]].push_back(vec[i - 1]);
            }
        }

        vector<bool> vis(n, false);
        int remain = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                dfs(i, edges, vis);
                ++remain;
            }
        }

        return n - remain;
    }
};