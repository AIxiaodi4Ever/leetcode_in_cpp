// leetcode:215
/*
Find the kth largest element in an unsorted array. Note that it is the kth largest 
element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 �� k �� array's length.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/kth-largest-element-in-an-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·1������ѡ��
// ���������ŦԪ�Ŀ���ѡ�񣬶�����������ֵ�ָ����о�Ӧ�ò��

// ����˼·��������һ��max��Ȼ�����k-1��deletemax֮�󷵻ضѶ�Ԫ��
// �������˶������˼·�����ǲ�û�н�maxԪ�������Ԫ�ؽ��н�����ɾ��������deletemax

// ������ŦԪ��λ������
int partition(int *nums, int left, int right)
{
    // nums[right]����ŦԪ
    int x = nums[right];
    int i = left - 1;
    for (int j = left; j < right; ++j)
    {
        // ����һ�����飬��С�ڵ���x��ȫ����ǰ��
        if (nums[j] <= x)
        {
            int temp = nums[++i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    // ����ŦԪ���ض�Ӧλ��
    nums[right] = nums[i + 1];
    nums[i + 1] = x;

    // ���ص���i + 1!!!
    return i + 1;
}

int random_partition(int *nums, int left, int right)
{
    int pivot_index = left + rand() % (right - left + 1);
    int pivot = nums[pivot_index];

    // ����ŦԪ�Ƶ�ĩβ�������
    nums[pivot_index] = nums[right];
    nums[right] = pivot;

    return partition(nums, left, right);
}

int quickSelect(int *nums, int left, int right, int index)
{
    int position = random_partition(nums, left, right);
    if (position == index)
    {
        return nums[position];
    }
    else
    {
        // position - 1��position + 1������position
        return position < index ? quickSelect(nums, position + 1, right, index)
                                : quickSelect(nums, left, position - 1, index);
    }
}

int findKthLargest(int* nums, int numsSize, int k)
{
    srand(time(NULL));
    return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}