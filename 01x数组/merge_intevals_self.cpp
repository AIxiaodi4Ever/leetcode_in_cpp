/*题目描述：
Given a collection of intervals, merge all overlapping intervals.

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

/* 解题思路：将输入区间的开始及结束的位置按大小排序，开始位置用*pstart表示，结束位置用*pend表示。
* 然后遍历排好序的开始及结束位置的数组，使用row表示第row个区间，如果pstart[row + 1] > pend[row]，
* 则合并区间，区间开始位置为开始遍历*pend之前记录的开始位置。
*/

/*
#include <stdio.h>
#include <stdlib.h>
*/
int my_compare(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

// 输入参数：intervals是数组指针，常规用法
// 输入参数：intervalsSize是数组行数，常规用法
// 输入参数：intervalsColSize是数组列数指针，我又不去改它列数，为什么要指针而不是整型，求指教，划为迷惑用法
// 输出参数：returnSize是返回数组行数，此处指定方便平台编译，可以理解，因此默认需要手动初始化，也就是印证了上面Note的说法，常规用法
// 输出参数：returnColumnSizes是返回列数的数组指针，非常迷惑，极尽困扰，稍一不慎，显得自己很笨，先说明它不是返回二维数组的二级指针，
//用法如下分解，归为变态用法
/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    // 分别为开始位置，结束为止及返回数组
    int *pstart = (int *)malloc(sizeof(int) * intervalsSize);
    int *pend = (int *)malloc(sizeof(int) * intervalsSize);
    int **preturn = (int **)malloc(sizeof(int *) * intervalsSize);

    int row = 0;        // 行数
    *returnSize = 0;    // 初始化返回的行数
    *returnColumnSizes = (int *)malloc(sizeof(int) * intervalsSize);
    for (row = 0; row < intervalsSize; row++)
    {
        preturn[row] = (int *)malloc(sizeof(int) * (*intervalsColSize));
        pstart[row] = intervals[row][0];
        pend[row] = intervals[row][1];
    }

    // 排序
    qsort(pstart, intervalsSize, sizeof(int), my_compare);
    qsort(pend, intervalsSize, sizeof(int), my_compare);

    // 遍历，合并
    for (row = 0; row < intervalsSize; row++)
    {
        preturn[*returnSize][0] = pstart[row];

        // row < intervalsSize的判断必须在前面，否则heap-use-overflow
        while (row < intervalsSize - 1 && pstart[row + 1] <= pend[row])
            row++;

        preturn[*returnSize][1] = pend[row];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    return preturn;
}