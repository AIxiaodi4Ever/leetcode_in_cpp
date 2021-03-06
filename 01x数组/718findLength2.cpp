// leetcode:718
// 方法二：滚动窗口
// 暴力解法的问题在于最坏情况下，导致O(N^3)的算法，所有元素都相同的两个数组导致最坏情况；
// 而最坏情况出现的原因是，相同元素没有对齐，因此可以通过移动数组的相对位置，使不同元素分别对齐；
// 如果存在最大相同子序列，则总有一次会使它们对其；
// 对齐方式有两种，1.固定A移动B，2.固定B移动A，因此总时间复杂度为O((M+N)*min(M,N))比动态规划多了一个常数；
// 但是，空间复杂度为O(1),远远小于动态规划的O(M*N);

#define max(a,b) ((a > b) ? a : b)
#define min(a,b) ((a < b) ? a : b)

// 每次A或B移动一个后，计算此时相同位置上的最大相同子序列
int maxLength(int *A, int *B, int indexA, int indexB, int len)
{
    int ret = 0, k = 0;
    for (int i = 0; i < len; i++)
    {
        if (A[indexA + i] == B[indexB + i])
        {
            k++;
        }
        else
        {
            k = 0;
        }
        ret = max(ret, k);
    }
    return ret;
}

int findLength(int* A, int ASize, int* B, int BSize)
{
    int ans = 0, len = 0;
    // 固定A，向后移动B
    for (int i = 0; i < ASize; i++)
    {
        len = min(ASize - i, BSize);
        // 下面这种情况不可能找到更大的ans
        if (ans >= len)
            break;
        int ret = maxLength(A, B, i, 0, len);
        ans = max(ans, ret);
    }

    // 固定B，向后移动A，循环控制变量用j以示区别
    for (int j = 0; j < BSize; j++)
    {
        len = min(ASize, BSize - j);
        // 下面这种情况不可能找到更大的ans
        if (ans >= len)
            break;
        int ret = maxLength(A, B, 0, j, len);
        ans = max(ans, ret);
    }

    return ans;
}
