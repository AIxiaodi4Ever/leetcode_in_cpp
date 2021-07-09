// leetcode:35

int searchInsert(int* nums, int numsSize, int target)
{
    if (nums == NULL)
        return 0;
    int left = 0, right = numsSize - 1;
    int mid, ans = numsSize;
    while (left <= right)
    {
    mid = left + ((right - left) >> 1);
    // ????==...
        if (target <= nums[mid])
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}