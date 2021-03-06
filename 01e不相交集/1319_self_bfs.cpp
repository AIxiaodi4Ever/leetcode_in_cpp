class Solution {
private:
    vector<vector<int>> edges;
    vector<bool> visited;

public:
    void bfs(int u)
    {
        visited[u] = true;
        queue<int> q;
        q.push(u);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (const auto& i : edges[node])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if (connections.size() < n - 1)
            return - 1;
        
        edges.resize(n);
        for (const auto& iv : connections)
        {
            // 双向边，所以push_back两次
            edges[iv[0]].push_back(iv[1]);
            edges[iv[1]].push_back(iv[0]);
        }
        int ans = 0;
        visited.resize(n);
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                bfs(i);
                ++ans;
            }
        }

        return ans - 1;
    }
};