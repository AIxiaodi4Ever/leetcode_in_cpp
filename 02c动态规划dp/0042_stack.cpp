// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
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
                int curWidth = i - left - 1;
                int curHeight = min(height[i], height[left]) - height[top];
                ans += curWidth * curHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};