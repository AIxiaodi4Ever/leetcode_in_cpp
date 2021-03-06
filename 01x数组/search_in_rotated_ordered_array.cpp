/*��Ŀ������
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

// ����˼·��nums[center]��ֵ�����������Ҫô�ڵ�һ���������䣬Ҫô�ڵڶ�����������
// ��һ�������target����nums[left]��С��nums[center]ʱ�޸�right��ֵ������nums[center]��С��nums[left]ʱ�޸�leftֵ
// �ڶ��������target����nums[center]��С��nums[right]ʱ�޸�leftֵ��С��nums[center]������nums[left]ʱ�޸�rightֵ
// �������ҵ�����center���Ҳ�������-1


int search(int* nums, int numsSize, int target)
{
    int left, right, center;
    left = 0;
    right = numsSize - 1;

    while (right >= left)
    {
        center = left + (right - left) / 2;
        
        // �ҵ��򷵻�λ��
        if (target == nums[center])
            return center;

        // center������������
        else if (nums[left] <= nums[center])
        {
            // >= �� <
            if (target >= nums[left] && target < nums[center])
                right = center - 1;       
            else           
                left = center + 1;
            

        }

        // center���Ҳ��������
        else
        {
            // > �� <=
            if (target > nums[center] && target <= nums[right])
                left = center + 1;
            else
                right = center - 1;
        }
    }

    return -1;
}