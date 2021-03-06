// 面试题 08.03
// 原本接着第一小问的意思是二分查找
// 而直接看这题使用遍历+跳跃性更好

class Solution {
public:
    int findMagicIndex(vector<int>& nums) 
    {
        int len = nums.size();
        int i = 0;
        while ( i < len )
        {
            if (nums[i] == i)
                return i;
            if (nums[i] > i)
            {
                i = nums[i];
                continue;
            }
            ++i;
        }
        return -1;
    }
};