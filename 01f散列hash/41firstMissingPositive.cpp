// leetcode:41
// description:
/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

Note:
Your algorithm should run in O(n) time and uses constant extra space.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/first-missing-positive
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ʹ��һ��hash���ʱ��ΪO(N), �ռ�ΪO(N);
// ������1��N������ʱ��ΪO(N), �ռ�ΪO(1);
// ��ˣ���������޸����飬��ô������ʱ��O(N)�ҿռ�O(1)���㷨��

// ����˼·��ԭ�����޸ĳ�hash��
// �����СΪN������Сmissing������ֻ����[1,N+1]֮����������Զ���������޸ĵ�ǰ���£�
// 1.�������飬��������ֵ��ΪN+1��
// 2.�ٴα������飬��������־���ֵ��С��[1,N]֮�����x������λ��**x-1**�ϵ���Ϊ����(��Ϊ������0��ʼ)��
// 3.�ٴα��������飬���������������˵����С��missing����ΪN+1�������һ��������λ�þ�����Сmissing positive��

int firstMissingPositive(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] <= 0)
        {
            nums[i] = numsSize + 1;
        }
    }

    for (int i = 0; i < numsSize; i++)
    {
        int temp = abs(nums[i]);
        if (temp > 0 && temp <= numsSize)
        {
            nums[temp - 1] = -abs(nums[temp - 1]);
        } 
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
            return i + 1;
    }

    return numsSize + 1;
}