class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) 
            return 0;
        vector<int> leftMaxs(n, height[0]), rightMaxs(n, height[n - 1]);
        for (int i = 1; i < n; ++i) {
            leftMaxs[i] = max(height[i], leftMaxs[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            rightMaxs[i] = max(height[i], rightMaxs[i + 1]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans += min(leftMaxs[i], rightMaxs[i]) - height[i];
        }
        return ans;
    }
};