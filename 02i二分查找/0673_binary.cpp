class Solution {
public:
    int binarySearch(int n, function<bool(int)> f) {
        int left = 0 , right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f(mid)) {
                right = mid;
            }    
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> d;
        vector<vector<int>> cnt;
        for (int v : nums) {
            int i = binarySearch(d.size(), [&](int i) {return d[i].back() >= v;});
            int c = 1;
            if (i > 0) {
                int k = binarySearch(d[i - 1].size(), [&](int k){return d[i - 1][k] < v;});
                c = cnt[i - 1].back() - cnt[i - 1][k];
            }
            if (i == d.size()) {
                d.push_back({v});
                cnt.push_back({0, c});
            }
            else {
                d[i].push_back(v);
                cnt[i].push_back(cnt[i].back() + c);
            }
        }
        return cnt.back().back();
    }
};