class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        // 否则可能除以0
        int d = max(1, (maxVal - minVal) / (n - 1));
        int bucketsNum = (maxVal - minVal) / d + 1;
        vector<pair<int, int>> buckets(bucketsNum, {-1, -1});
        for (const int &num : nums)
        {
            int idx = (num - minVal) / d;
            if (buckets[idx].first == -1)
                buckets[idx].first = buckets[idx].second = num;
            else
            {
                buckets[idx].first = min(buckets[idx].first, num);
                buckets[idx].second = max(buckets[idx].second, num);
            }
        }
        int prev = -1;
        int ret = 0;
        for (int i = 0; i < bucketsNum; ++i)
        {
            if (buckets[i].first == -1)
                continue;
            if (prev != -1)
                ret = max(ret, buckets[i].first - buckets[prev].second);
            prev = i;
        }
        return ret;
    }
};