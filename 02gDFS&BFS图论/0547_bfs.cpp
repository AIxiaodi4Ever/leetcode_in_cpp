class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        queue<int> Q;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                Q.push(i);
                vis[i] = true;
                while (!Q.empty())
                {
                    int cur = Q.front();
                    Q.pop();
                    for (int j = 0; j < n; ++j)
                    {
                        if (isConnected[cur][j] && !vis[j])
                        {
                            Q.push(j);
                            vis[j] = true;
                        }
                    }
                }
                ++ans;
            }
        }
        return ans;
    }
};