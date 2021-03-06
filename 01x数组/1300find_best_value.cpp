// leetcode:1300
/* description:
 * Given an integer array arr and a target value target, return the integer 
 * value such that when we change all the integers larger than value in the 
 * given array to be equal to value, the sum of the array gets as close as 
 * possible (in absolute difference) to target.
 * In case of a tie, return the minimum such integer.
 * 
 * Notice that the answer is not neccesarilly a number from arr.
 * 
 * Example 1:
 * Input: arr = [4,9,3], target = 10
 * Output: 3
 * Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
 * 
 * Example 2:
 * Input: arr = [2,3,5], target = 10
 * Output: 5
 * 
 * Example 3:
 * Input: arr = [60864,25176,27249,21296,20204], target = 56803
 * Output: 11361
 * 
 * Constraints:
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i], target <= 10^5
 * 
 * ��Դ�����ۣ�LeetCode��
 * ���ӣ�https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target
 * ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·��������ֲ���
// value�ķ�Χ��[0, max(arr)], ��L = 0, r = max��arr��, ��������ֲ��Ҵ��м�ֵmid = (L + r) / 2,��ʼ����value��
// �Ƚ���������Ȼ��Ϊ�˼���ת���Ժ������ͣ��ȼ���ǰ׺��prefix;
// �ڲ���ֲ��������д��ڵ���value����Сֵ������iter�������أ�������ʱ����arrSize��
// ���������������ڵ���iter��ֵȫ����Ϊvalue��Ȼ���������ͣ�
// ������iter˵��ǰiter������С��value��
// �������ڱ�����ǰ׺��prefix������ͺܺü��㣺sum = prefix(iter) + (arrSize - iter) * value;
// �Ƚ�sum��target�����sum <= target, value = (��ʱ��)mid,Ȼ����L = mid + 1,���������м�ֵ���б���
// ������r = mid - 1, ֱ��L > rΪֹ��
// �����value��value+1�и�������ѡ��һ�����أ���Ϊ����������valueʹת�����������ӽ���С��target��
// value+1ʹת���������ӽ��Ҵ��ڵ���target��

int my_compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

// ���ֲ��ң����������д��ڵ���value����Сֵ��������
// ���ߵ�������������С��valueʱ�����������С��
int binary_find(int *arr, int arrSize, int value)
{
    int left = 0, right = arrSize - 1, mid;
    int ans = -1;
    mid = (left + right) / 2;
    while (left <= right)
    {
        if (arr[mid] < value)
            left = mid + 1;
        else
        {
            ans = mid;
            right = mid - 1;
        }

        mid = (left + right) / 2;
    }


    if (ans >= 0)
        return ans;
    // ��������value��ֵ == �������ֵʱ������value+1�������������
    // �����������е�����С��value+1��
    // ��ʱ����arrSize����ʾarr��ǰarrSize�����������е�����С��value��
    else
        return arrSize;
}

int findBestValue(int* arr, int arrSize, int target)
{
    // ����С��������
    qsort(arr, arrSize, sizeof(int), my_compare);
    // ǰ׺���ȸ���ֵΪ0
    int *prefix = (int *)calloc(arrSize + 1, sizeof(int));

    // ����ǰ׺��
    for (int i = 1; i <= arrSize; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    // �����ֲ��ҵĳ�ʼֵ
    int L = 0, r = arr[arrSize - 1], mid;
    int value = -1;
    mid = (L + r) / 2;

    // �����ֲ��ң�����ʹת�������С��target����С��value
    while(L <= r)
    {
        int iter;
        iter = binary_find(arr, arrSize, mid);
        // ��������iter˵��ǰiter������С��mid��iter���ܵ���arrSize��
        int cur_sum = prefix[iter] + (arrSize - iter) * mid;
        // cur_sumС��ʱ����mid������Ҫ�ҵ�ֵ(value)
        if (cur_sum < target)
        {
            value = mid;
            L = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
        mid = (L + r) / 2;
    }

    // �˳�ѭ��ʱ��value��ֵһ����ʹת������ĺ�С�ڵ���ӽ�target��ֵ
    // �����С��ת�������
    int iter = binary_find(arr, arrSize, value);
    int small = prefix[iter] + (arrSize - iter) * value;

    // ����ϴ��ת�������
    iter = binary_find(arr, arrSize, value + 1);
    int big;
    // ��������������С��valueʱ�᷵��arrSize
    if (iter != arrSize)
        big = prefix[iter] + (arrSize - iter) * (value + 1);
    else
        big = prefix[iter];

    return abs(small - target) <= abs(big - target) ? value : value + 1;
}