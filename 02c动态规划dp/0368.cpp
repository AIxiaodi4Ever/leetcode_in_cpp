class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int maxVal = nums[0], maxSize = 1;
        // 首先动态规划计算出选择nums[i]时的最大整除子集的大小
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    // 注意题解中没有重复元
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if (dp[i] > maxSize) {
                    maxVal = nums[i];
                    maxSize = dp[i];
                } 
            }  
        }

        // 第二步倒叙找出最大整除子集
        vector<int> res;
        if (maxSize == 1) {
            res.push_back(nums[0]);
            return res;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (dp[i] == maxSize && maxVal % nums[i] == 0) {
                res.push_back(nums[i]);
                maxVal = nums[i];
                --maxSize;
            }
        }

        return res;
    }
};