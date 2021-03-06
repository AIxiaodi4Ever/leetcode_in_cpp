// leetcode:15
/* description:
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 * [-1, 0, 1],
 * [-1, -1, 2]
 * ]
 * 
 * ��Դ�����ۣ�LeetCode��
 * ���ӣ�https://leetcode-cn.com/problems/3sum
 * ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 */

/*****  ����˼·  *****/
// ����+˫ָ��
// ���������򣬵�һ��˳�������Ϊ�˱�֤triplet���ظ���ֻ�е�ǰnums[first] != nums[first]-1��first==0ʱ���Ž����²����
// �ڶ����������˫ָ�룬��Ϊ����������a�̶�������£�b��С���������c�Ӵ�С��������һ��second < third��������
// �Լ�nums[second] != nums[second - 1]��֤triplet���ظ������Եõ����к�Ϊ0����Ԫ���顣

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// �ȽϺ�����*a<*bʱ��a����bǰ�棬*a==*bʱ˳��ȷ����
// �����������ʱ�����෴ֵ��
int my_cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // ����СΪ(N)(N-1)(N-2) / 2;
    // ����������������Χ�����ֻ����ƽ������С���ڴ�
    int **ans = (int **)malloc(sizeof(int *) * numsSize * numsSize / 2);
    int i = 0;
    if (nums == NULL)
        return NULL;

    // ʵ��Ӧ��ʹ��һ�����鱣��������nums
    qsort(nums, numsSize, sizeof(int), my_cmp);

    // �����ѭ��
    for (int first = 0; first < numsSize; first++)
    {
        // ��֤���ظ�
        if (first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }

        // third��ʼʱָ��ָ�����Ҷ�
        int third = numsSize - 1;
        int target = -nums[first];
        for (int second = first + 1; second < numsSize; second++)
        {
            // ��֤���ظ�
            if (second > first + 1 && nums[second] == nums[second - 1])
            {
                continue;
            }

            // ��֤secondС��third
            while (second < third && nums[second] + nums[third] > target)
            {
                third--;
            }

            // ��second == thirdʱ����������������˵��b��������ʱ
            // nums[first] + nums[second] + nums[third] > 0��һֱ����
            // ��ʱ���Է��ص���һ��ѭ��
            if (second == third)
            {
                break;
            }

            // ����������д��ans
            if (nums[second] + nums[third] == target)
            {
                ans[i] = (int *)malloc(sizeof(int) * 3);
                ans[i][0] = nums[first];
                ans[i][1] = nums[second];
                ans[i][2] = nums[third];
                i++;
            }
        }
    }

    *returnSize = i;
    // returnColumnSizes�ĵ�һ�������ÿһ�м�¼����ansÿһ�е�����������
    // ���ﶼ��3������ȫ����ֵΪ3
    // �����ֵ������һ��ʼ��������ڴ�����
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * i);
    for (int j = 0; j < i; j++)
    {
        (*returnColumnSizes)[j] = 3;
    }
    return ans;
}