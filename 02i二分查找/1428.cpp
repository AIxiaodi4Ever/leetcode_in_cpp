class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // 不用乘法，防止溢出
        if (m > bloomDay.size() / k) {
            return -1;
        }
        int high = 0, low = INT_MAX;
        int length = bloomDay.size();
        for (int i = 0; i < length; ++i) {
            high = max(high, bloomDay[i]);
            low = min(low, bloomDay[i]);
        }

        while (low < high) {
            int days = low + (high - low) / 2;
            // high = days-1是因为除法会向下取整
            // 这样取high仍然一定能成，而low最多等于high
            if (canMake(bloomDay, m, k, days)) {
                high = days;
            }
            else {
                low = days + 1;
            }
        }
        return low;
    }

    bool canMake(vector<int>& bloomDay, int m, int k, int days) {
        int flowers = 0;
        int bouquets = 0;
        int length = bloomDay.size();
        for (int i = 0; i < length; ++i) {
            if (bloomDay[i] <= days) {
                ++flowers;
                if (flowers == k) {
                    ++bouquets;
                    flowers = 0;
                }
            }
            else {
                flowers = 0;
            }
        }
        // 大于等于，不是等于，，
        return bouquets >= m;
    }
};