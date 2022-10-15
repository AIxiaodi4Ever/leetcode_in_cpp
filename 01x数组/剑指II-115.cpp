class Solution {
public:
    // topological sort. If only one topological order exists, the super-sequence is unique
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> indegree(n + 1);
        vector<unordered_set<int>> graph(n + 1);
        for (auto& sequence : sequences) {
            for (int i = 1; i < sequence.size(); ++i) {
                int prev = sequence[i - 1], next = sequence[i];
                if (!graph[prev].count(next)) {
                    graph[prev].emplace(next);
                    ++indegree[next];
                }
            }
        }
        queue<int> qu;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) {
                qu.emplace(i);
            }
        }
        while (!qu.empty()) {
            if (qu.size() > 1) {
                return false;
            }
            int num = qu.front();
            qu.pop();
            for (int next : graph[num]) {
                if (--indegree[next] == 0) {
                    qu.emplace(next);
                }
            }
        }
        return true;
    }
};