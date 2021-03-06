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
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路：两层二分查找
// value的范围是[0, max(arr)], 即L = 0, r = max（arr）, 因此外层二分查找从中间值mid = (L + r) / 2,开始查找value；
// 先将数组排序，然后为了计算转变以后的数组和，先计算前缀和prefix;
// 内层二分查找数组中大于等于value的最小值的索引iter，并返回，不存在时返回arrSize；
// 将数组内索引大于等于iter的值全部变为value，然后计算数组和；
// 索引是iter说明前iter个数都小于value；
// 所以由于保存了前缀和prefix，数组和很好计算：sum = prefix(iter) + (arrSize - iter) * value;
// 比较sum与target，如果sum <= target, value = (此时的)mid,然后令L = mid + 1,继续计算中间值进行遍历
// 否则令r = mid - 1, 直到L > r为止。
// 最后在value和value+1中根据条件选择一个返回，因为由以上描述value使转变数组和是最接近且小于target，
// value+1使转变数组和最接近且大于等于target。

int my_compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

// 二分查找，返回数组中大于等于value的最小值的索引，
// 或者当数组所有数都小于value时，返回数组大小。
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
    // 当遍历到value的值 == 数组最大值时，查找value+1则会出现这种情况
    // 即数组中所有的数都小于value+1；
    // 此时返回arrSize，表示arr中前arrSize个数，即所有的数都小于value；
    else
        return arrSize;
}

int findBestValue(int* arr, int arrSize, int target)
{
    // 先由小到大排序
    qsort(arr, arrSize, sizeof(int), my_compare);
    // 前缀和先赋初值为0
    int *prefix = (int *)calloc(arrSize + 1, sizeof(int));

    // 计算前缀和
    for (int i = 1; i <= arrSize; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    // 外层二分查找的初始值
    int L = 0, r = arr[arrSize - 1], mid;
    int value = -1;
    mid = (L + r) / 2;

    // 外层二分查找，查找使转变数组和小于target的最小的value
    while(L <= r)
    {
        int iter;
        iter = binary_find(arr, arrSize, mid);
        // 索引等于iter说明前iter个数都小于mid，iter可能等于arrSize；
        int cur_sum = prefix[iter] + (arrSize - iter) * mid;
        // cur_sum小于时表明mid可能是要找的值(value)
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

    // 退出循环时，value的值一定是使转变数组的和小于但最接近target的值
    // 计算较小的转变数组和
    int iter = binary_find(arr, arrSize, value);
    int small = prefix[iter] + (arrSize - iter) * value;

    // 计算较大的转变数组和
    iter = binary_find(arr, arrSize, value + 1);
    int big;
    // 数组中所有数都小于value时会返回arrSize
    if (iter != arrSize)
        big = prefix[iter] + (arrSize - iter) * (value + 1);
    else
        big = prefix[iter];

    return abs(small - target) <= abs(big - target) ? value : value + 1;
}