class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int i, int n)
    {
        vis[i] = true;
        for (int j = 0; j < n; ++j)
        {
            if (isConnected[i][j] && !vis[j])
                dfs(isConnected, vis, j, n);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0 ; i < n; ++i)
        {
            if (!vis[i])
            {
                dfs(isConnected, vis, i, n);
                ++ans;
            }
        }
        return ans;
    }
};