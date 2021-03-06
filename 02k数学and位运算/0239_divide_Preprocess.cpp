class Solution {
public:
    /********************************************************/
    /* 将数组按照k个一组进行分组，最后一组的元素数目可能小于k  */
    /* 计算每一组某一位置的前缀最大值和后缀最大值             */
    /* prefixMax[i]表示i对应的分组中以i结尾的前缀的最大值     */
    /* suffixMax[i]表示i对应的分组中以i开始的后缀的最大值     */
    /* 如果i是k的倍数那么i就是以i结尾的前缀的唯一元素         */
    /* 如果i+1是k的倍数那么i就是以i开始的后缀的唯一元素       */
    /*******************************************************/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        // 前缀只能从头开始，后缀只能从尾结束
        int n = nums.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        // 求以i结尾的前缀最大值
        for (int i = 0; i < n; ++i)
        {
            if (i % k == 0)
                prefixMax[i] = nums[i];
            else
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
        // 求以i开始的后缀最大值
        for (int i = n - 1; i >= 0; --i)
        {
            if (i == n - 1 || (i + 1) % k == 0)
                suffixMax[i] = nums[i];
            else
                suffixMax[i] = max(suffixMax[i + 1], nums[i]);
        }

        vector<int> ans;
        for (int i = 0; i <= n - k; ++i)
            ans.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
        return ans;
    }
};