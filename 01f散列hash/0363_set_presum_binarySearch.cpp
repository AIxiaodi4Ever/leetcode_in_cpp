class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;  // 和可能是负数，所以ans初始化为INT_MIN
        for (int i = 0; i < m; ++i) {
                vector<int> sum(n);
            for (int j = i; j < m; ++j) {
                for (int c = 0; c < n; ++c) {
                    sum[c] += matrix[j][c];
                }
                // si表示前i个数相加, 0代表s0
                set<int> orderedPreSum{0}; 
                int s = 0;
                for (int val : sum) {
                    s += val;
                    set<int>::iterator lb = orderedPreSum.lower_bound(s - k);
                    if (lb != orderedPreSum.end()) {
                        ans = max(ans, s - *lb);
                    }
                    orderedPreSum.insert(s);
                } // val
            }// j
        }// i
        return ans;
    }
};