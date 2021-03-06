class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        vector<int> buf(n);
        int exp = 1;
        int maxVal = *max_element(nums.begin(), nums.end());
        while (maxVal >= exp)
        {
            vector<int> cnt(10);
            for (int i = 0; i < n; ++i)
            {
                int digit = (nums[i] / exp) % 10;
                ++cnt[digit];
            }
            for (int i = 1; i < 10; ++i)
                cnt[i] += cnt[i - 1];
            // 为了保证稳定性，必须反向填充数组
            for (int i = n - 1; i >= 0; --i)
            {
                int digit = (nums[i] / exp) % 10;
                buf[--cnt[digit]] = nums[i];
            }
            // 为了下一次排序，先将这次的结果保存在nums中
            copy(buf.begin(), buf.end(), nums.begin());
            exp *= 10;
        }
        int ret = 0;
        for (int i = 1; i < n; ++i)
            ret = max(ret, buf[i] - buf[i - 1]);
        return ret;
    }
};