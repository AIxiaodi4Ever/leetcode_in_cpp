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
You may assume k is always valid, 1 ≤ k ≤ array's length.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路1：快速选择
// 基于随机枢纽元的快速选择，而不是三数中值分隔，感觉应该差不多

// 解题思路二构造了一个max堆然后进行k-1次deletemax之后返回堆顶元素
// 即利用了堆排序的思路，但是并没有将max元素与最后元素进行交换并删除，仅仅deletemax

// 返回枢纽元的位置索引
int partition(int *nums, int left, int right)
{
    // nums[right]是枢纽元
    int x = nums[right];
    int i = left - 1;
    for (int j = left; j < right; ++j)
    {
        // 遍历一遍数组，将小于等于x的全部放前面
        if (nums[j] <= x)
        {
            int temp = nums[++i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    // 将枢纽元换回对应位置
    nums[right] = nums[i + 1];
    nums[i + 1] = x;

    // 返回的是i + 1!!!
    return i + 1;
}

int random_partition(int *nums, int left, int right)
{
    int pivot_index = left + rand() % (right - left + 1);
    int pivot = nums[pivot_index];

    // 将枢纽元移到末尾方便遍历
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
        // position - 1和position + 1而不是position
        return position < index ? quickSelect(nums, position + 1, right, index)
                                : quickSelect(nums, left, position - 1, index);
    }
}

int findKthLargest(int* nums, int numsSize, int k)
{
    srand(time(NULL));
    return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}