/*��Ŀ������
Given a collection of intervals, merge all overlapping intervals.

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

/* ����˼·������������Ŀ�ʼ��������λ�ð���С���򣬿�ʼλ����*pstart��ʾ������λ����*pend��ʾ��
* Ȼ������ź���Ŀ�ʼ������λ�õ����飬ʹ��row��ʾ��row�����䣬���pstart[row + 1] > pend[row]��
* ��ϲ����䣬���俪ʼλ��Ϊ��ʼ����*pend֮ǰ��¼�Ŀ�ʼλ�á�
*/

/*
#include <stdio.h>
#include <stdlib.h>
*/
int my_compare(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

// ���������intervals������ָ�룬�����÷�
// ���������intervalsSize�����������������÷�
// ���������intervalsColSize����������ָ�룬���ֲ�ȥ����������ΪʲôҪָ����������ͣ���ָ�̣���Ϊ�Ի��÷�
// ���������returnSize�Ƿ��������������˴�ָ������ƽ̨���룬������⣬���Ĭ����Ҫ�ֶ���ʼ����Ҳ����ӡ֤������Note��˵���������÷�
// ���������returnColumnSizes�Ƿ�������������ָ�룬�ǳ��Ի󣬼������ţ���һ�������Ե��Լ��ܱ�����˵�������Ƿ��ض�ά����Ķ���ָ�룬
//�÷����·ֽ⣬��Ϊ��̬�÷�
/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    // �ֱ�Ϊ��ʼλ�ã�����Ϊֹ����������
    int *pstart = (int *)malloc(sizeof(int) * intervalsSize);
    int *pend = (int *)malloc(sizeof(int) * intervalsSize);
    int **preturn = (int **)malloc(sizeof(int *) * intervalsSize);

    int row = 0;        // ����
    *returnSize = 0;    // ��ʼ�����ص�����
    *returnColumnSizes = (int *)malloc(sizeof(int) * intervalsSize);
    for (row = 0; row < intervalsSize; row++)
    {
        preturn[row] = (int *)malloc(sizeof(int) * (*intervalsColSize));
        pstart[row] = intervals[row][0];
        pend[row] = intervals[row][1];
    }

    // ����
    qsort(pstart, intervalsSize, sizeof(int), my_compare);
    qsort(pend, intervalsSize, sizeof(int), my_compare);

    // �������ϲ�
    for (row = 0; row < intervalsSize; row++)
    {
        preturn[*returnSize][0] = pstart[row];

        // row < intervalsSize���жϱ�����ǰ�棬����heap-use-overflow
        while (row < intervalsSize - 1 && pstart[row + 1] <= pend[row])
            row++;

        preturn[*returnSize][1] = pend[row];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    return preturn;
}