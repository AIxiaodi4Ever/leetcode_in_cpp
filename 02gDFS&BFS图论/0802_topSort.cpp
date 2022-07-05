class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rg(n);
        vector<int> inDeg(n, 0);

        // reverse the graph ans count indegree
        for (int i = 0; i < n; ++i) {
            for (int y : graph[i]) {
                rg[y].push_back(i);
            }
            inDeg[i] = graph[i].size();
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : rg[x]) {
                if (--inDeg[y] == 0) {
                    q.push(y);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};