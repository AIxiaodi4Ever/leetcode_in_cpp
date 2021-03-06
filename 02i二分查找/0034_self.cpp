class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size() - 1;
        int mid = right / 2;
        while (left <= right && nums[mid] != target)
        {
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = left + (right - left) / 2;
        }
        if (left > right)
            return {-1, -1};
        else
        {
            int targetLeft = mid, targetRight = mid;
            while (targetLeft >= 0 && nums[targetLeft] == target)
            {
                if (targetLeft - 1 < 0 || nums[targetLeft - 1] != target)
                    break;
                --targetLeft;
            }
            while (targetRight < nums.size() && nums[targetRight] == target)
            {
                if (targetRight + 1 == nums.size() || nums[targetRight + 1] != target)
                    break;
                ++targetRight;
            }
            return {targetLeft, targetRight};
        }
    }
};