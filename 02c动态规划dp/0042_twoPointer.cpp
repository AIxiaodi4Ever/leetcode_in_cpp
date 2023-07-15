// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1, leftMax = height[0], rightMax = height[n - 1];
        int ans = 0;
        while (left != right)
        {
            if (height[left] >= height[right])
            {
                ans += (rightMax - height[right]);
                --right;
                rightMax = max(rightMax, height[right]); 
            } else {
                ans += (leftMax - height[left]);
                ++left;
                leftMax = max(leftMax, height[left]);
            }
        }
        return ans;
    }
};