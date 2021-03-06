// leetcode:16
/*
description:
Given an array nums of n integers and an integer target, find three integers in nums such 
that the sum is closest to target. Return the sum of the three integers. You may assume that 
each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Constraints:
    3 <= nums.length <= 10^3
    -10^3 <= nums[i] <= 10^3
    -10^4 <= target <= 10^4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/3sum-closest
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·
// ������������ͣ����������˫ָ�뼴�ɣ�����뱣��ԭ���飬���½�һ�����鱣������������
// 1. ��nums����֮�����ѭ��������һ������Ϊ�˱�֤���ظ���nums[first] != nums[first - 1]��first == 0ʱ���Ž����²������
// 2. ��һ��ѭ������second��first+1��third��numsSize-1��ʼ����֤second < third��Ȼ�󲻶ϼ��������Ͳ�����ans������͵���targetֱ�ӷ��أ�
// 3. ����͸��ӽ�target�����ans�����������С��ans���ƶ�second����֤С��(����)third�Ҳ��ظ����������ans����third���ƣ�
// 4. ��󷵻�ans��Ϊ��ӽ��Ĵ�.

int my_cmp(void *i1, void *i2)
{
    return *(int *)i1 - *(int *)i2;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    int ans = nums[0] + nums[1] + nums[2];

    // ����
    qsort(nums, numsSize, sizeof(int), my_cmp);

    // ����������һ����
    for (int first = 0; first < numsSize; first++)
    {   
        // ��֤���ظ�
        if (first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }

        // �ڲ�˫ָ��ѭ��
        int second = first + 1, third = numsSize - 1;
        while (second < third)
        {
            int sum = nums[first] + nums[second] + nums[third];

            // ���target��ͬ
            if (sum == target)
            {
                return target;
            }

            // ����ú͸�Ϊ�ӽ�target�����ans
            if (abs(sum - target) < abs(ans - target))
            {
                ans = sum;
            }

            // �����ʹ���target�����ƶ�third
            if (sum > target)
            {
                // ���ܵ���second == third��������������´�ѭ����
                third--;
                // ��֤���ظ�
                while (second < third && nums[third] == nums[third + 1])
                {
                    third--;
                }
            }

            // ������С��target�����ƶ�second
            if (sum < target)
            {
                // ���ܵ���second == third��������������´�ѭ����
                second++;
                // ��֤���ظ�
                while(second < third && nums[second] == nums[second - 1])
                {
                    second++;
                }
            }
        }
    }

    return ans;
}