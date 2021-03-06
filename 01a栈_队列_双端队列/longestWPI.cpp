/* 
��Ŀ����
We are given hours, a list of the number of hours worked per day for a given employee.
A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
A well-performing interval is an interval of days for which the number of tiring days is strictly larger than 
the number of non-tiring days.
Return the length of the longest well-performing interval.

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-well-performing-interval
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 */

// ����˼·��
// ǰ׺��+����ջ
// ����hours��ֻ�д���8��С�ڵ���8���������������8��ʾΪ1��С�ڵ���8��ʾΪ-1��ת��������arr��
// ԭ����ת��Ϊ������ĺʹ���0���������г�������ߵĳ���
// ��ʹ�����鱣��ǰ׺��presum�Ժ����������кͿ���ͨ����ǰ׺�͵ļ�����������磺
// arr[1] + arr[2] +...+ arr[6] = presum[7] - presum[1];
// ԭ��⣺https://leetcode-cn.com/problems/longest-well-performing-interval/solution/can-kao-liao-ji-ge-da-shen-de-ti-jie-zhi-hou-zong-/

#define max(a, b) (((a) >= (b)) ? (a) : (b))

int longestWPI(int* hours, int hoursSize)
{
    int presum[hoursSize + 1];
    int stk[hoursSize + 1], top;
    int best_int = 0;
    int i;

    // ��hours����ת����1��-1����,������ǰ׺��
    presum[0] = 0;
    top = 0;
    stk[0] = 0;
    for (i = 0; i < hoursSize; i++)
    {
        if (hours[i] > 8)
            presum[i + 1] = presum[i] + 1;
        else
            presum[i + 1] = presum[i] - 1;
        
        // ��ǰ׺�͵ݼ���Ԫ��������ջ
        if (presum[i + 1] < presum[stk[top]])
        {
            stk[++top] = i + 1;
        }
    }

    for (int j = hoursSize; j >= 0; j--)
    {
        while (top >= 0)
        {
            // ִ������жϣ����ٶ��������
            if (j <= stk[top])
            {
                top--;
                break;
            }
            else if ((presum[j] - presum[stk[top]]) > 0)
            {
                best_int = max(best_int, j - stk[top]);
                top--;
            }
            else
                break;
        }
    }

    return best_int;
}