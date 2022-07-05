class Solution {
public:
    vector<int> val;
    vector<vector<int>> rec;

    int solve(int left, int right) {
        if (left >= right - 1) {
            return 0;
        }
        if (rec[left][right] != -1) {
            return rec[left][right];
        }
        for (int i = left + 1; i < right; ++i) {
            int sum = val[left] * val[right] * val[i];
            sum += solve(left, i) + solve(i, right);
            rec[left][right] = max(sum, rec[left][right]);
        }
        return rec[left][right];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n + 2);
        for (int i = 0; i < n; ++i) {
            val[i + 1] = nums[i];
        }
        val[0] = val[n + 1] = 1;
        rec.resize(n + 2, vector<int>(n + 2, -1));
        return solve(0, n + 1);
    }
};