class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower)
    {
        int left = 0, right = nums.size() - 1, ans = nums.size();
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            // 这里更新ans
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
                ans = mid;
            }    
            else
                left = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int leftIdx = binarySearch(nums, target, true);
        // 注意这里-1
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
        return {leftIdx, rightIdx};
        return {-1, -1};
    }
};