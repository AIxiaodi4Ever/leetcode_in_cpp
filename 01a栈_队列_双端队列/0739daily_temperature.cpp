/* leetcode:739 */
/* description:
 * Given a list of daily temperatures T, return a list such that, for each day in the input, 
 * tells you how many days you would have to wait until a warmer temperature. If there is no 
 * future day for which this is possible, put 0 instead.
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output 
 * should be [1, 1, 4, 2, 1, 1, 0, 0].
 * Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an 
 * integer in the range [30, 100]. 
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// �ⷨһ��������ʹ��һ�������¶ȷ�Χ��[30, 100]��ʹ��һ��next���鱣��ÿһ���¶�������ֵ�λ��;
// next��Ԫ�س�ʼ��Ϊ����󣬷����������T������ÿ��T[i]����next���ҵ�����T[i]+1��100�У�ÿ���¶ȵ�һ�γ��ֵ��±�;
// ����������Сֵ���ΪwarmerIndex����T[warmerIndex]Ϊ��һ�α�T[i]�ߵ�ֵ�����warmerIndex�������������ans[i] = warmerIndex - i;
// �����next[T[i]] = i;    ʱ�临�Ӷ�O(nm), �ռ临�Ӷ�O(m)��n��T�Ĵ�С��m��next�Ĵ�С��

// ����ʹ�ýⷨ����
// ά��һ������ջ���������T�����ջ��Ԫ��С��T[i]����ջ��Ԫ��T[prev_index]��ջ������ans[prev_index]��ֵΪi - prev_index;
// ���ջΪ�գ���ջ��Ԫ�ش��ڵ���T[i]����T[i]��ջ��
// ans��ʼȫ����ֵΪ0��
int* dailyTemperatures(int* T, int TSize, int* returnSize)
{
    // Ϊans����ռ��ͬʱ��ʼ��Ϊ0
    int *ans = (int *)calloc(TSize, sizeof(int));
    int temp_stack[TSize], top = -1;

    // ���Ϊ�գ����ؿ�
    if (T == NULL)
        return NULL;

    // �����������
    for (int i = 0; i < TSize; i++)
    {
        // ��ջ��Ϊ����ջ��Ԫ��С��T[i]ʱ����ջ������ans��Ӧ��λ�ø�ֵ
        while (top >= 0 && T[temp_stack[top]] < T[i])
        {
            ans[temp_stack[top]] = i - temp_stack[top];
            top--;

        }

        // ջ��Ϊ�ջ�ջ��Ԫ�ش���T[i]ʱ����ջ
        top++;
        temp_stack[top] = i;
    }

    *returnSize = TSize;
    return ans;
}