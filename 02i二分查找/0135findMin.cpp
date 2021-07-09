// leetcode:135
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.
You may assume no duplicate exists in the array.

Example 1:
Input: [3,4,5,1,2] 
Output: 1

Example 2:
Input: [4,5,6,7,0,1,2]
Output: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size() - 1;
        int pivot = 0;
        while (low < high)
        {
            pivot = low + (high - low) / 2;
            // 因为没有重复元素，所以不考虑等于
            if (nums[pivot] < nums[high])
                // 令high == pivot实际上相当于用high表示当前寻找到的最小元素
                // 因此最后返回nums[high]; 实际上最后满足low == high
                high = pivot;
            else
                low = pivot + 1;
        }
        return nums[high];
    }
};