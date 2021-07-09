class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> slideWindow;
        for (int i = 0; i < n; ++i) {
            set<int>::iterator iter = slideWindow.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (iter != slideWindow.end() && (*iter) <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            slideWindow.insert(nums[i]);
            if (i >= k) {
                slideWindow.erase(nums[i - k]);
            }
        }
        return false;
    }
};