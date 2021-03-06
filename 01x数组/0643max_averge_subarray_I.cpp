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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-average-subarray-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

// 如果记录了i到i+k的和sum，那么i+1到i+k+1的和可以根据sum = sum - nums[i] + nums[i+k+1]计算得到
// 如果后者大，则更新res，最后返回sum / k 即可。
// 这种做法相比记录前缀和并遍历空间复杂度由O(N)减小至O(1)

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

    // 因为时整型数组
    return (double)res / k;
}