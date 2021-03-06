/*
题目描述：
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
*/

/* 解题思路

利用异或运算^的特点

    0和任何数异或等于该数
    任何数和自身异或等于0
    异或运算满足交换律

当将一个数组的数全部按位异或后，可以将成对的数放在前面先运算，而成对的数经过上述1,2会得到0，也就达到了消去成对的数的目的。

此时数组中剩下两个不同的数异或，得到的结果mask是这两个数不同的位上值为1，相同的为0.

但这样没办法把两个数分离出来。既然这两个不同的数必然有位是不同的，并且异或的结果也告诉我们哪些位不同。我们不妨以mask的最低的值为1的位（设为a0位）来区分这两个数，其中一个数a0位等于1，另一个等于0.

其中通过位运算x & (-x)得到a0 = 1，其他位为0的结果。

同样我们将数组中其他的数，也分成两组：a0 = 0组和a0 = 1组，这样保证了两个不同的数分在两组，也保证了成对的数必在其中一组而不会一对数分在两组。

再分别对两组的数进行异或运算，最后得到的两个数即所求。

作者：imane
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/wei-yun-suan-tql-by-imane/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

// TQL，原来还有这种做法
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    int num1 = 0, num2 = 0, mask = 0;
    int i;
    int *retArr = (int *)malloc(sizeof(int) * 2);

    // 只有两个不同的数
    *returnSize = 2;

    for (i = 0; i < numsSize; i++)
    {
        mask ^= nums[i];
    }

    mask = mask & (-mask);

    for (i = 0; i < numsSize; i++)
    {
        // a0位为0的数
        if ((mask & nums[i]) == 0)
        {
            num1 ^= nums[i];
        }
        // a0位为1的数
        else
        {
            num2 ^= nums[i];
        }
    }

    retArr[0] = num1;
    retArr[1] = num2;
    return retArr;
}
