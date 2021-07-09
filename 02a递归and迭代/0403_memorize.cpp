class Solution {
public:
    vector<unordered_map<int, bool>> rec;

    bool dfs(vector<int>& stones, int i, int lastDist) {
        if (i == stones.size() - 1) {
            return true;
        }

        if (rec[i].count(lastDist)) {
            return rec[i][lastDist];
        }

        for (int curDist = lastDist - 1; curDist <= lastDist + 1; ++curDist) {
            if (curDist > 0) {
                int j = lower_bound(stones.begin() + i, stones.end(), curDist + stones[i]) - stones.begin();
                if (j != stones.size() && curDist + stones[i] == stones[j] && dfs(stones, j, curDist)) {
                    return rec[i][lastDist] = true;
                }
            }
        }

        return rec[i][lastDist] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        rec.resize(n);
        return dfs(stones, 0, 0);
    }
};