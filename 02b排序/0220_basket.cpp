class Solution {
public:
    int getId(int x, long w) {
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            long x = nums[i];
            int id = getId(x, t + 1ll);
            if(mp.count(id)) {
                return true;
            }
            if (mp.count(id - 1) && abs(x - mp[id - 1]) <= t) {
                return true;
            }
            if (mp.count(id + 1) && abs(x - mp[id + 1]) <= t) {
                return true;
            }
            mp[id] = x;
            if (i >= k) {
                mp.erase(getId(nums[i - k], t + 1ll));
            }
        }
        return false;
    }
};