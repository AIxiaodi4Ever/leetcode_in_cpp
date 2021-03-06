class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size(), len = 1;
        if (n == 0)
            return 0;
        // d[i]中保存的是长度为i的末尾元素最小的递增子序列的末尾元素
        // 初始值是几不重要，因为循环时只考虑i及i前面的元素，都已确定，且不考虑位置0
        vector<int> d(n + 1, 0);    
        // 忘记初始化d[1]导致结果可能大1的错误
        d[len] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            // 如果nums[i]大于d[len]说明递增序列的长度可以增加
            if (nums[i] > d[len])
                d[++len] = nums[i];
            // 否则更新数组d的前面二分查找d中最后一个d[len']小于nums[i]的len'将d[len'+1]更新为nums[i]
            // 因为使用了二分查找，所以原本的d[len'+1]一定大于等于nums[i]，保证了长度为len'+1的子序列增长最慢
            // 题解中说找到d中第一个小于nums[i]的d[k]应该是笔误，或者意思是倒着找
            else
            {
                // 从1开始
                int left = 1, right = len, pos = 0;
                while (left <= right)
                {
                    int mid = left + ((right - left) >> 1);
                    //int mid = (left + right) >> 1;
                    if (d[mid] < nums[i])
                    {
                        left = mid + 1;
                        pos = mid;  
                    }
                    else
                        right = mid - 1;
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};