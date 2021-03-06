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
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/3sum
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*****  解题思路  *****/
// 排序+双指针
// 将数组排序，第一层顺序遍历，为了保证triplet不重复，只有当前nums[first] != nums[first]-1或first==0时，才进行下层遍历
// 第二层遍历利用双指针，因为数组已排序，a固定的情况下，b从小到大遍历，c从大到小遍历，再一个second < third的条件，
// 以及nums[second] != nums[second - 1]保证triplet不重复。可以得到所有和为0的三元数组。

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 比较函数，*a<*b时，a排在b前面，*a==*b时顺序不确定。
// 因此逆序排列时返回相反值。
int my_cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // 最大大小为(N)(N-1)(N-2) / 2;
    // 但分配过大过超出范围，因此只分配平方级大小的内存
    int **ans = (int **)malloc(sizeof(int *) * numsSize * numsSize / 2);
    int i = 0;
    if (nums == NULL)
        return NULL;

    // 实际应该使用一个数组保存排序后的nums
    qsort(nums, numsSize, sizeof(int), my_cmp);

    // 最外层循环
    for (int first = 0; first < numsSize; first++)
    {
        // 保证不重复
        if (first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }

        // third开始时指向指针最右端
        int third = numsSize - 1;
        int target = -nums[first];
        for (int second = first + 1; second < numsSize; second++)
        {
            // 保证不重复
            if (second > first + 1 && nums[second] == nums[second - 1])
            {
                continue;
            }

            // 保证second小于third
            while (second < third && nums[second] + nums[third] > target)
            {
                third--;
            }

            // 当second == third时，由于数组已排序，说明b继续增加时
            // nums[first] + nums[second] + nums[third] > 0会一直成立
            // 此时可以返回到第一层循环
            if (second == third)
            {
                break;
            }

            // 满足条件，写入ans
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
    // returnColumnSizes的第一个数组的每一列记录数组ans每一行的列数。。。
    // 这里都是3，所以全部赋值为3
    // 在最后赋值避免了一开始分配过大内存的情况
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * i);
    for (int j = 0; j < i; j++)
    {
        (*returnColumnSizes)[j] = 3;
    }
    return ans;
}