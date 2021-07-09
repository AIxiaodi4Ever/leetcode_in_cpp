class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return false;
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int curHeight = min(height[left], height[i]) - height[top];
                int curWidth = i - left - 1;
                ans += curWidth * curHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};