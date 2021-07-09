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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
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
            // ��Ϊû���ظ�Ԫ�أ����Բ����ǵ���
            if (nums[pivot] < nums[high])
                // ��high == pivotʵ�����൱����high��ʾ��ǰѰ�ҵ�����СԪ��
                // �����󷵻�nums[high]; ʵ�����������low == high
                high = pivot;
            else
                low = pivot + 1;
        }
        return nums[high];
    }
};