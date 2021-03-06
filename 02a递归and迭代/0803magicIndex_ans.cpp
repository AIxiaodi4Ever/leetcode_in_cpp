// 面试题 08.03
// 题解递归+二分查找法

class Solution {
public:
    int getAnswer(const vector<int>& nums, int left, int right)
    {
        if (left > right)
            return -1;
        
        int mid = left + (right - left) / 2;
        int leftans = getAnswer(nums, left, mid - 1);
        if (leftans != -1)
            return leftans;
        if (nums[mid] == mid)
            return mid;
        return getAnswer(nums, mid + 1, right);
        
    }
    int findMagicIndex(vector<int>& nums) 
    {
        return getAnswer(nums, 0, nums.size() - 1);
    }
};