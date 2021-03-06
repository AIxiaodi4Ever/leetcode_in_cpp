class Solution {
public:
    int minSwapsCouples(vector<int>& row) 
    {
        int n = row.size();
        int tot = n / 2;
        vector<vector<int>> graph(tot);
        for (int i = 0; i < n; i += 2)
        {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            if (l != r)
            {
                graph[l].push_back(r);
                graph[r].push_back(l);
            }
        }

        vector<bool> visited(tot, false);
        int ans = 0;
        for (int i = 0; i < tot; ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue<int> q;
                q.push(i);
                int cnt = 0;
                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();
                    cnt += 1;
                    for (int y : graph[x])
                    {
                        if (!visited[y])
                        {
                            visited[y] = true;
                            q.push(y);
                        }
                    }
                }
                ans += cnt - 1;
            }
        }
        return ans;
    }
};