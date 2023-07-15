// 882. Reachable Nodes In Subdivided Graph
class Solution {
public:
    // the total possible edges number is n square so we use n scale to encode edge
    int encodeEdge(int u, int v, int n) {
        return u * n + v;
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // modify the graph to a adjacent list
        vector<vector<pair<int, int>>> adList(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], cnt = edge[2];
            adList[u].emplace_back(v, cnt);
            adList[v].emplace_back(u, cnt);
        }

        // count the reachable node
        unordered_map<int, int> used;  // the key is encoded edge, value is reachable subnode in this edge
        unordered_set<int> visited;   // flags to indicate weather the node have been visited
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    // value.second is the reachable node, value.first is the steps needed to reach it.
        pq.emplace(0, 0);
        int reachableNodes = 0;
        while (!pq.empty()) {
            auto [steps, u] = pq.top(); // can NOT use auto&, because the pop operation below
            pq.pop();
            if (visited.count(u)) {
                continue;
            }
            visited.emplace(u);
            ++reachableNodes;
            for (auto [v, cnt] : adList[u]) {
                if (steps + cnt + 1 <= maxMoves && !visited.count(v)) {
                    pq.emplace(steps + cnt + 1, v);
                }
                used[encodeEdge(u, v, n)] = min(cnt, maxMoves - steps);
            }         
        }

        // count the reachable subnode
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], cnt = edge[2];
            reachableNodes += min(cnt, used[encodeEdge(u, v, n)] + used[encodeEdge(v, u, n)]);
        }

        return reachableNodes;
    }
};