class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        // 贪心的算法每次选择最高的峰和最低的谷
        // 即选择极值点
        int length = nums.size();
        if (length < 2)
            return length;
        int preDiff = nums[1] - nums[0];
        int ret = preDiff != 0 ? 2 : 1;
        for (int i = 2; i < length; ++i)
        {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && preDiff <= 0) || (diff < 0 && preDiff >= 0))
            {
                ++ret;
                preDiff = diff;
            }
        }
        return ret;

    }
};