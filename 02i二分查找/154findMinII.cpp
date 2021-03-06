// leetcode:154
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
The array may contain duplicates.

Example 1:
Input: [1,3,5]
Output: 1

Example 2:
Input: [2,2,2,0,1]
Output: 0

Not
    This is a follow up problem to Find Minimum in Rotated Sorted Array.
    Would allow duplicates affect the run-time complexity? How and why?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
            if (nums[pivot] < nums[high])
                high = pivot;
            else if (nums[pivot] > nums[high])
                low = pivot + 1;
            // ������
            else    
                --high;
        }
        return nums[high];
    }
};