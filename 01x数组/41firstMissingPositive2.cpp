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

// ����˼·���û�
// ���[1��N]֮�������x���֣�������λ��x-1�����ֽ�������������x����λ��x-1;
// ע��������ظ��ĳ��֣��򽻻���һֱ���У�����Ӧ�ü�һ���ж�������

int firstMissingPositive(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        // ������while������if����Ϊ�ı���nums[i]��ֵ
        while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1])
        {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }

    return numsSize + 1;
}