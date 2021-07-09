class Solution {
public:
    static constexpr int K = 100;

    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<int> ans(q);
        vector<vector<int>> preFreqSum(n + 1, vector<int>(K + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= K; ++j) {
                preFreqSum[i][j] = preFreqSum[i - 1][j];
            }
            preFreqSum[i][nums[i - 1]]++;
        }

        vector<int> v;

        // 与resize不同，reserve只改变容量（capacity）不改变大小（size）
        v.reserve(K); // 容量最大为100，预先分配容量避免运行时容量动态增长
        for (int i = 0; i < q; ++i) {
            // clear只重置大小，不改变容量
            v.clear();
            int left = queries[i][0], right = queries[i][1];
            for (int j = 1; j <= K; ++j) {
                if (preFreqSum[right + 1][j] - preFreqSum[left][j] > 0) {
                    v.push_back(j);
                }
            }//j
            if (v.size() == 1) {
                ans[i] = -1;
            }
            else {
                ans[i] = K;
                for (int j = 0; j + 1 < v.size(); ++j) {
                    ans[i] = min(ans[i], abs(v[j] - v[j + 1]));
                }//j
            }
        }//i
        return ans;
    }
};