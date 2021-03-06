/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// Ҫ��C���Եĺ�����������ˣ������ܽ�һ���÷���֮��Ͱ�������ʹ�ã�ר�����㷨����Ҫ�����﷨�������˷�ʱ����
// ���������������

/*
���ߣ�hua-jia-wang-tie-nan
���ӣ�https://leetcode-cn.com/problems/merge-intervals/solution/chun-c-leetcodeer-wei-shu-zu-can-shu-shi-yong-xiao/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

#define IN 
#define OUT
// ������
#define __________FRAME_START__________
#define __________FRAME_END__________

static int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
// ���������intervals������ָ�룬�����÷�
// ���������intervalsSize�����������������÷�
// ���������intervalsColSize����������ָ�룬���ֲ�ȥ����������ΪʲôҪָ����������ͣ���ָ�̣���Ϊ�Ի��÷�
// ���������returnSize�Ƿ��������������˴�ָ������ƽ̨���룬������⣬���Ĭ����Ҫ�ֶ���ʼ����Ҳ����ӡ֤������Note��˵���������÷�
// ���������returnColumnSizes�Ƿ�������������ָ�룬�ǳ��Ի󣬼������ţ���һ�������Ե��Լ��ܱ�����˵�������Ƿ��ض�ά����Ķ���ָ�룬
//�÷����·ֽ⣬��Ϊ��̬�÷�
int** merge(IN int** intervals, IN int intervalsSize, IN int* intervalsColSize, OUT int* returnSize, OUT int** returnColumnSizes){
    int* pStart = (int*)malloc(intervalsSize * sizeof(int)); 
    int* pEnd = (int*)malloc(intervalsSize * sizeof(int));

    __________FRAME_START__________

    int row = 0; // �������У���ά����϶����õ�
    int col = 0;
    *returnSize = 0; // ��ʼ��returnSize

    int** pRes = (int**)malloc(intervalsSize * sizeof(int*));
    // �ڶѿռ�����ά���飬������malloc������������ջ�ռ�ֱ�Ӷ������飬��Ȼ�޷�����
    // ���巵������Ķ���ָ�룬Ԫ�ظ���Ϊ��������һ��Ѷ�ά���鿴��һ��˳���ÿ�������һ������
    // ����returnColumnSizes = (int**)malloc(intervalsSize * sizeof(int*));�������壬��������ָ������䲻������������������
    for (row = 0; row <= intervalsSize - 1; row++)
    {
        pRes[row] = (int*)malloc(*intervalsColSize * sizeof(int)); // Ϊÿ��������һ������ռ䣬Ԫ�ظ���Ϊ����
        pStart[row] = intervals[row][0];
        pEnd[row] = intervals[row][1];
    } // ��ʱ���صĶ�ά���鴴�����
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int)); 
    // Ϊ���ص�returnColumnSizesָ�������ʼ������һ�οռ�
    // Ԫ�ظ���Ϊ������ÿ��Ԫ��������Ÿ��е�����

    __________FRAME_END__________

    qsort(pStart, intervalsSize, sizeof(int), comp);
    qsort(pEnd, intervalsSize, sizeof(int), comp);

    for (row = 0; row <= intervalsSize - 1; row++)
    {
        __________FRAME_START__________

        pRes[*returnSize][0] = pStart[row]; 
        // Ϊ�������鸳ֵ���˴��õ���returnSizeָ��������������������±꣬���ע��Ҫ��*
        // ��ȻҲ���Զ����µ��±����count�����ֵ��returnSize���У�ƽ̨����*returnSizeȥ�����صĶ�ά�������Ч�ռ�
        for ( ; row <= intervalsSize - 2; row++)
        {
            if (pStart[row + 1] > pEnd[row])
            {
                break;  
            }
        }
        pRes[*returnSize][1] = pEnd[row];
        (*returnColumnSizes)[*returnSize] = 2;
        // �ӻ����ˣ�����Ҫÿ�θ�returnColumnSize��ֵ����ֵ����������ͬ���е��ã���������ͬ���Թ���
        // ע�����ȼ���[]�����ȼ���*�ߣ�����Ҫ�����ţ���Ϊ�Ǹ�*returnColumnSizes�����˿ռ䣬û��returnColumnSizes������ռ�
        (*returnSize)++;
        // �����������У���������Ⱥ��±����1�������returnSize�����±��øպõ�����

        __________FRAME_END__________
    }

    return pRes;
}
