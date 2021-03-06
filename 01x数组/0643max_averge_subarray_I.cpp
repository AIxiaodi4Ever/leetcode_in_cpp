// leetcode:643
/* description:
 * Given an array consisting of n integers, find the contiguous subarray of 
 * given length k that has the maximum average value. And you need to output 
 * the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75

Note:
    1 <= k <= n <= 30,000.
    Elements of the given array will be in the range [-10,000, 10,000].

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-average-subarray-i
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 * 
 */

// �����¼��i��i+k�ĺ�sum����ôi+1��i+k+1�ĺͿ��Ը���sum = sum - nums[i] + nums[i+k+1]����õ�
// ������ߴ������res����󷵻�sum / k ���ɡ�
// ����������ȼ�¼ǰ׺�Ͳ������ռ临�Ӷ���O(N)��С��O(1)

#define max(a,b) (((a) >= (b)) ? (a) : (b))

double findMaxAverage(int* nums, int numsSize, int k)
{
    int sum = 0;
    int res;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    res = sum;

    for (int i = k; i < numsSize; i++)
    {
        sum += nums[i] - nums[i - k];
        res = max(res, sum);
    }

    // ��Ϊʱ��������
    return (double)res / k;
}