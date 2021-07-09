class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnt;
        for (auto& brickRow : wall) {
            int sum = 0;
            int n = brickRow.size();
            // 不能考虑最后一块砖的右边界，因为属于墙的右边界
            for (int i = 0; i < n - 1; ++i) {
                sum += brickRow[i];
                ++cnt[sum];
            }
        }

        int maxCnt = 0;
        for (auto& [_, c] : cnt) {
            maxCnt = max(maxCnt, c);
        }
        return wall.size() - maxCnt;
    }
};